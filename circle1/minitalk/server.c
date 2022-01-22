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

void handle_siguser2()
{

}
void handle_siguser1()
{

}
int main () {


	int pid = getpid();

	write(1,"server PID : ",13);
	ft_putnbr_fd(pid,1);

	sigaction(SIGUSR1,handle_siguser1);
	sigaction(SIGUSR2,handle_siguser2);

	while(1){
		pause()
	}

	return 1;
}