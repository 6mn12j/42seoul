/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 15:30:07 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_make_thread(t_info *info)
{
	t_philo	*philo;
	int		i;
	int		flag;

	i = -1;
	flag = 1;
	while (++i < info->philo_num)
	{
		philo = &info->philos[i];
		if (!philo->thread)
			flag = ft_error("thread 스레드가 생성 되지 않았습니다.", info);
		if (!philo->is_die)
			flag = ft_error("is_die 스레드가 생성 되지 않았습니다.", info);
	}
	if (!info->is_must_eat)
		flag = ft_error("is_must_eat 스레드가 생성 되지 않았습니다.", info);
	if (!flag)
		return (0);
	return (1);
}

static int	sit_info(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < info->philo_num)
	{
		philo = &info->philos[i];
		pthread_create(&philo->thread, NULL, philo_routine, (void *)philo);
		pthread_create(&philo->is_die, NULL, is_die, (void *)philo);
		pthread_detach(philo->thread);
		pthread_detach(info->philos[i].is_die);
		i ++;
	}
	if (info->must_eat != -1)
	{
		pthread_create(&info->is_must_eat, NULL, is_must_eat, (void *)info);
		pthread_detach(info->is_must_eat);
	}
	return (check_make_thread(info));
}

static void	ft_wait(t_info *info)
{
	while (!info->is_finished)
		usleep(500);
	return ;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!ft_check_valid(argc, argv))
		return (1);
	if (argc == 5 || argc == 6)
	{
		if (!init_info(argc, argv, &info) || !init_philo(&info))
		{
			printf("%s \n", "init Error");
			return (0);
		}
		if (!sit_info(&info))
			return (ft_error("sit_info Error", &info));
		ft_wait(&info);
	}
}
