/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/01/22 18:13:10 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_validate_input(int argc, char **argv, t_info *info)
{
	if (argc != 3)
	{
		write(1, "Argument Error", 14);
		return (0);
	}
	info -> pid = ft_atoi(argv[1]);
	info -> message = argv[2];
	if (info -> pid <= 99 || info -> pid > 100000)
	{
		write(1, "PID Error", 9);
		return (0);
	}
	return (1);
}

void	send_msg(t_info *info)
{
	int	i;
	int	bit;
	int	signal;

	i = 0;
	while (info->message[i])
	{
		bit = 0x80;
		while (bit)
		{
			signal = bit & info->message[i];
			if (signal)
				kill(info->pid, SIGUSR2);
			else
				kill(info->pid, SIGUSR1);
			usleep(100);
			bit = bit >> 1;
		}
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (ft_validate_input(argc, &*argv, &info))
		send_msg(&info);
	return (0);
}
