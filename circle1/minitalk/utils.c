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

static void		int_to_char(int num, int fd)
{
	int fin;

	fin = num % 10;
	if (num == 0)
		return ;
	num = num / 10;
	int_to_char(num, fd);
	ft_putchar_fd(fin + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long long num;
	long long fin;

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

static int	is_space(char *c)
{
	if (*c == '\t'
			|| *c == '\n'
			|| *c == '\v'
			|| *c == '\f'
			|| *c == '\r'
			|| *c == ' ')
		return (1);
	return (0);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

static int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;
	char		*temp;

	temp = (char*)str;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(&temp[i]))
		i++;
	if (temp[i] == '-' || temp[i] == '+')
		sign = temp[i++] == '-' ? -1 : 1;
	if(!ft_isdigit(temp[i]))
		return (-1);
	while (ft_isdigit(temp[i]))
	{
		result = (result * 10) + (temp[i] - '0');
		if (sign * result < -2147483648)
			return (0);
		else if (sign * result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}

char			*ft_itoa(int n)
{
	long long	num;
	char		*temp;
	size_t		len;

	num = n;
	len = 0;
	if (num <= 0)
	{
		len = ft_strlen(num) + 1;
		num = num * -1;
	}
	else
		len = ft_strlen(num);
	if (!(temp = malloc(sizeof(char) * len + 1)))
		return (0);
	temp[len] = '\0';
	while (len > 0)
	{
		temp[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		temp[0] = '-';
	return (temp);
}