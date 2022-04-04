/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 03:32:58 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_destroy(info->philos[i].left_fork);
		pthread_mutex_destroy(info->philos[i].right_fork);
		pthread_mutex_destroy(&info->philos[i].eating);
		pthread_mutex_destroy(&info->philos[i].fork);
		free(&info->philos[i]);
	}
	free(info->philos);
	info->philos = 0;
	printf("%s\n", str);
	return ;
}

void	ft_printf(char *str, t_philo *philo, time_t now)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("[%ldms] %d %s\n",now,philo->id,str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
