/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 15:27:16 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_die(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
	while (!philo->info->is_finished)
	{
		i = -1;
		while (++i < philo->info->philo_num)
		{
			pthread_mutex_lock(&philo->eating);
			if (philo->time_die <= get_time())
			{
				pthread_mutex_lock(&philo->info->print_mutex);
				printf("[%ldms] %d %s\n", get_time(), philo->id, "is Die");
				philo->info->is_finished = TRUE;
				ft_free(philo->info);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->eating);
			usleep(500);
		}
	}
	return (NULL);
}

void	*is_must_eat(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	while (info->fin_eat_cnt != info->philo_num)
		usleep(500);
	info->is_finished = TRUE;
	ft_free(info);
	pthread_mutex_unlock(&info->print_mutex);
	return (NULL);
}
