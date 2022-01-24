/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:10:24 by minjupar          #+#    #+#             */
/*   Updated: 2022/01/22 17:13:29 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_info
{
	int			pid;
	char		*message;
}				t_info;

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
