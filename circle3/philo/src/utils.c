/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/08 15:51:30 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *str, t_info *info)
{
	if (info->philos)
		free(info->philos);
	info->philos = NULL;
	printf("%s\n", str);
	return (0);
}

void	ft_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	if (philo->info->is_finished)
		return ;
	printf("[%ldms] %d %s\n", get_time(), philo->id, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

static int	check_argument(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("argument 에러 정수만 가능합니다\n");
			return (0);
		}
	}
	return (1);
}

int	ft_check_valid(int argc, char *argv[])
{
	if (!check_argument(argv[1]) || !check_argument(argv[2]) || \
		!check_argument(argv[3]) || !check_argument(argv[4]))
		return (0);
	if (argc == 6)
		return (check_argument(argv[5]));
	return (1);
}

void	ft_free(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		pthread_mutex_unlock(&info->philos[i].fork);
		pthread_mutex_unlock(&info->philos[i].eating);
		pthread_mutex_destroy(&info->philos[i].fork);
		pthread_mutex_destroy(&info->philos[i].eating);
	}
	pthread_mutex_unlock(&info->print_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	if (info->philos)
		free(info->philos);
	info->philos = NULL;
}
