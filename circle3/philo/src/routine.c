/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 16:25:16 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//철학자는 먹고 나서 포크를 두고 잠 (eating -> sleeping)
//철학자는 자고 나서 생각함 (sleeping -> thinking)
static void	*eating(t_philo *philo);
static void	*sleeping(t_philo *philo);

static void	*pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_printf("pickup left", philo, get_time());
	pthread_mutex_lock(philo->right_fork);
	ft_printf("pickup right", philo, get_time());
	return (eating);
}

static void	*eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&philo->eating);
	now = get_time();
	philo->current_eat_cnt++;
	if (philo->current_eat_cnt == philo->info->must_eat)
		philo->info->fin_eat_cnt++;
	philo->time_die = now + philo->info->time_to_die;
	ft_printf("eating....", philo, now);
	time_flow(now, philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (sleeping);
}

static void	*thinking(t_philo *philo)
{
	ft_printf("thinking....", philo, get_time());
	return (pickup);
}

static void	*sleeping(t_philo *philo)
{
	time_t	now;

	now = get_time();
	ft_printf("sleeping....", philo, now);
	time_flow(now, philo->info->time_to_sleep);
	return (thinking);
}

void	*philo_routine(void *arg)
{
	void	*(*routine)(t_philo *philo);
	t_philo	*philo;

	philo = (t_philo *)arg;
	routine = pickup;
	if (philo->id % 2 == 1)
		usleep(philo->info->time_to_eat * 500);
	while (!philo->info->is_finished)
		routine = routine(philo);
	return (NULL);
}
