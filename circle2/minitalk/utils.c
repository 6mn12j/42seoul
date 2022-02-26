/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:54:46 by minjupar          #+#    #+#             */
/*   Updated: 2022/01/22 17:54:47 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

static void	int_to_char(int num, int fd)
{
	int	fin;

	fin = num % 10;
	if (num == 0)
		return ;
	num = num / 10;
	int_to_char(num, fd);
	ft_putchar_fd(fin + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	long long	fin;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	fin = num % 10;
	int_to_char(num / 10, fd);
	ft_putchar_fd(fin + '0', fd);
}

static int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	char		*temp;
	long long	result;

	temp = (char *)str;
	result = 0;
	i = 0;
	if (!ft_isdigit(temp[i]))
		return (-1);
	while (ft_isdigit(temp[i]))
	{
		result = (result * 10) + (temp[i] - '0');
		i++;
	}
	return ((int)(result));
}
