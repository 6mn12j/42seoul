/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 04:35:22 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *str, t_info *info)
{
	free(info->philos);
	info->philos = 0;
	printf("%s\n", str);
	return (0);
}

void	ft_printf(char *str, t_philo *philo, time_t now)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("[%ldms] %d %s\n", now, philo->id, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

static int	check_argument(char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]))
	{
		printf("argument 에러 정수만 가능합니다\n");
		return (0);
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
