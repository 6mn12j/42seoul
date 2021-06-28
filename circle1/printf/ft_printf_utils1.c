/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:44:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/26 20:07:29 by minjupar         ###   ########.fr       */
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

int		digitlen(int value)
{
	int		l;

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

void	handle_base(int nbr, int base)
{
	char c;

	if (nbr == 0)
		return ;
	handle_base(nbr / base, base);
	c = nbr % base + '0';
	write(1, &c, 1);
}

int		str_len(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[j] == '-')
			return (-1);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	char	c;

	i = str_len(base);
	if (nbr == -2147483648)
	{
		write(1, "-2147482648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr -= 1;
	}
	handle_base(nbr / i, i);
	c = (nbr % i) + '0';
	write(1, &c, 1);
}


