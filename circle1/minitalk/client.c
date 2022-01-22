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
	if (argc > 3){
		write(1,"format: [pid] [messge]", 22);
		exit(1);
	}

	info->pid = ft_atoi(argv[1]);
	info->message = argv[2];
	info->message_length = ft_strlen(argv[2]);
    if (info->pid <= 99 || info->pid > 100000) // pid 100 ~ 10000 까지의 값
	{
		write(1,"error",5);
		exit(1);
	}
    //TODO: 이외 에러처리
	return 1;
}

void send_bit(char c)
{
	//비트로 쪼개서 보내면 됨 .
	int bit = 0;
	while(0>>1)
	{
		if(bit === 8)
		{
			//널 넣어서
			return;
		}


	}
	write(1,&c,1);


	return;
}

int main(int argc, char* argv[]){
	//포맷 [pid] [message].
	t_info info;

	if(ft_validate_input(argc, &*argv, &info))
	{
		while(info.message_length--)
		{
			send_bit(info.message[info.message_length]);
		}
	}
	return(1);

}