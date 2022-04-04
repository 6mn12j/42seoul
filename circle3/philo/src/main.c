/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 03:40:05 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		check_make_thread(t_info *info)
{
	t_philo	*philo;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < info->philo_num)
	{
		philo = &info->philos[i];
		if (!philo->thread)
		{
			printf("%d %s\n", philo->id, "thread 스레드가 생성 되지 않았습니다.");
			flag = 1;
		}
		if (!philo->die_monitor)
		{
			printf("%s\n", "die_monitor 스레드가 생성 되지 않았습니다.");
			flag = 1;
		}
	}
	if (!info->must_eat_monitor)
	{
		printf("%s\n", "must_eat_monitor 스레드가 생성 되지 않았습니다.");
		flag = 1;
	}
	if (flag)
		return (0);
	return (1);
}

int		sit_info(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < info->philo_num)
	{
		philo = &info->philos[i];
		pthread_create(&philo->thread, NULL, philo_routine, (void *)philo);
		pthread_create(&philo->die_monitor, NULL, die_monitor, (void *)philo);
		pthread_detach(philo->thread);
		pthread_detach(info->philos[i].die_monitor);
		i ++;
	}
	if (info->must_eat != -1)
	{
		pthread_create(&info->must_eat_monitor, NULL, must_eat_monitor, (void *)info);
		pthread_detach(info->must_eat_monitor);
	}
	return (check_make_thread(info));
}

void	ft_wait(t_info *info)
{
	while (!info->is_finished)
		usleep(500);
	return ;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (!init_info(argc, argv, &info) || !init_philo(&info))
		{
			printf("%s \n", "init Error");
			return (0);
		}
		if (!sit_info(&info))
		{
			printf("%s \n", "sit_info Error");
			return (0);
		}
		ft_wait(&info);
	}
}
