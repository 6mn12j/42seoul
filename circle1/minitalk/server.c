/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:58 by minjupar          #+#    #+#             */
/*   Updated: 2022/01/22 16:47:58 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void signal_handler(int signal)
{
	static int bit;
	static char c;

	
	if(signal == SIGUSR2){
		c |= 1; 
		if (bit < 7)
			c <<= 1;

	}else if (signal == SIGUSR1){
		c |= 0; 
		if (bit < 7)
			c <<= 1;

	}
	
	bit++;
	if( bit == 8)
	{
		ft_putchar_fd(c,1);
		bit = 0;
		c = '\n';
		
	}
	
	return ;
}


int main (void) {
	
	ft_putstr_fd("[server PID] : ",1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	
}