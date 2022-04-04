/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 03:36:31 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_digit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;
	char		*temp;

	temp = (char *)str;
	sign = 1;
	result = 0;
	i = 0;
	if (temp[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (temp[i] == '+')
		i++;
	while (is_digit(temp[i]))
	{
		result = (result * 10) + (temp[i++] - '0');
		if (sign * result < -2147483648)
			return (0);
		else if (sign * result > 2147483647)
			return (-1);
	}
	return ((int)(result * sign));
}
