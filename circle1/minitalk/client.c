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

#include "stdlib.h"


int	ft_validate_input(int argc, char **argv, t_info *info)
{
	if (argc != 3){
		ft_putstr_fd("Argument Error",1);
		return(0);
	}

	info->pid = ft_atoi(argv[1]);
	info->message = argv[2];
	info->message_length = ft_strlen(argv[2]);

    if (info->pid <= 99 || info->pid > 100000) // pid 100 ~ 10000 까지의 값
	{
		ft_putstr_fd("PID Error",1);
		return(0);
	}
    //TODO: 이외 에러처리
	return (1);
}

void send_msg(t_info *info)
{
	int bit;
	int signal;
	int i;

	i = 0;
	while(i < info->message_length){
		bit = 1;
		
		while(bit <= 8){
			signal = info->message[i] >> (8 - bit) & 1;
			if (signal == 0)
			{
				if(kill(info->pid, SIGUSR1) == -1)
					ft_putstr_fd("실패",1);
			}
			else if (signal == 1)
			{
				if(kill(info->pid, SIGUSR2) == -1)
					ft_putstr_fd("실패",1);

			}
			usleep(100);
			bit++;
		}
		i++;
	}
	return;
}

int main(int argc, char* argv[]){
	t_info info;

	if(ft_validate_input(argc, &*argv, &info))
		send_msg(&info);
	
	return(0);

}