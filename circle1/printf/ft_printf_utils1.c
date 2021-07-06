/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:44:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/04 14:50:51 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
	return (0);
}

int		is_spec(const char c)
{
	if (c == 'c' || c == 's' ||
		c == 's' || c == 'd' ||
		c == 'i' || c == 'u' ||
		c == 'x' || c == 'X')
		return (1);
	return (-1);
}

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (len--)
		ptr[len] = (unsigned char)value;
	return (dest);
}

void	*ft_bzero(void *dest, size_t len)
{
	return (ft_memset(dest, 0, len));
}

size_t	ft_digitlen(long long value)
{
	size_t	l;

	l = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value = value / 10;
		l++;
	}
	return (l);
}
