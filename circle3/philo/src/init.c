/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 04:22:00 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	info->philos = philo;
	if (!philo)
		ft_error("philo malloc 실패", info);
	i = -1;
	while (++i < info->philo_num)
	{
		philo[i].info = info;
		philo[i].id = i;
		philo[i].current_eat_cnt = 0;
		philo[i].left_fork = &info->philos[i].fork;
		philo[i].right_fork = &info->philos[(i + 1) % info->philo_num].fork;
		philo[i].time_die = info->time_to_die;
		if (pthread_mutex_init(philo[i].left_fork, NULL) == -1 || \
			pthread_mutex_init(philo[i].right_fork, NULL) == -1 || \
			pthread_mutex_init(&philo[i].eating, NULL) == -1)
			ft_error("뮤텍스 초기화 실패", info);
	}
	return (1);
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat < 0)
			return (0);
	}
	else
		info->must_eat = -1;
	info->is_finished = FALSE;
	info->fin_eat_cnt = 0;
	if (pthread_mutex_init(&info->print_mutex, NULL) == -1)
		ft_error("뮤텍스 초기화 실패", info);
	return (1);
}
