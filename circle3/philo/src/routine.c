/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/08 15:51:09 by minjupar         ###   ########.fr       */
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
	ft_printf("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_printf("has taken a fork", philo);
	return (eating);
}

static void	*eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	philo->current_eat_cnt++;
	if (philo->current_eat_cnt == philo->info->must_eat)
		philo->info->fin_eat_cnt++;
	philo->time_die = get_time() + philo->info->time_to_die;
	ft_printf("is eating", philo);
	time_flow(get_time(), philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (sleeping);
}

static void	*thinking(t_philo *philo)
{
	ft_printf("is thinking", philo);
	return (pickup);
}

static void	*sleeping(t_philo *philo)
{
	ft_printf("is sleeping", philo);
	time_flow(get_time(), philo->info->time_to_sleep);
	return (thinking);
}

void	*philo_routine(void *arg)
{
	void	*(*routine)(t_philo *philo);
	t_philo	*philo;

	philo = (t_philo *)arg;
	routine = pickup;
	if (philo->id % 2 == 1)
		usleep(philo->info->time_to_eat * 100);
	while (!philo->info->is_finished)
		routine = routine(philo);
	return (NULL);
}
