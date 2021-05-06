/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:30:56 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/06 22:18:29 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	char	*temp;

	temp = (char*)str;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(&temp[i]))
		i++;
	if (temp[i] == '-' || temp[i] == '+')
		sign = temp[i++] == '-' ? -1 : 1;
	while (ft_isdigit(temp[i]))
	{
		result = (result * 10) + (temp[i] - '0');
		i++;
	}
	return (result * sign);
}
