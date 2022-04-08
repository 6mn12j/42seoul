/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/08 15:51:13 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_time(void)
{
	static time_t		start = 0;
	struct timeval		time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	if (start == 0)
		start = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start);
}

void	time_flow(time_t start_time, time_t target_time)
{
	while (1)
	{
		usleep(300);
		if (get_time() >= start_time + target_time)
			return ;
	}
}
