/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:44:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/29 20:26:07 by minjupar         ###   ########.fr       */
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

size_t		ft_digitlen(long long value)
{
	size_t	l;

	l = 0;
	if (!value)
		return (1);
	while (value)
	{
		value = value / 10;
		l++;
	}
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*temp;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(&temp[s1_len], s2, s2_len + 1);
	return (temp);
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

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// void	ft_putnbr_base(long long *nbr, char *base)
// {
// 	int		i;
// 	char	c;

// 	i = 16;
// 	while (nbr)
// 	{
// 		if (nbr == 0)
// 		return ;
// 		c = base[nbr % i];
// 		write(1, &c, 1);
// 		nbr = nbr / i;
// 	}
// 	return ;
// }


void	handle_base(long long  nbr, char *base)
{
	char c;

	if (nbr == 0)
		return ;
	handle_base(nbr / 16, base);
	c = base[nbr % 16];
	write(1, &c, 1);
	return ;
}

void	ft_putnbr_base(long long  nbr, char *base)
{
	char	c;

	handle_base(nbr / 16, base);
	c = base[nbr % 16];
	write(1, &c, 1);

	return ;
}