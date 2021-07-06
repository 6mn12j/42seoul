/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:15 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/04 14:48:47 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*dest;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	dest[s1_len + s2_len] = '\0';
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(&dest[s1_len], s2, s2_len + 1);
	return (dest);
}

char	*ft_itoa(long long n, t_flag *f)
{
	long long		num;
	size_t			len;
	char			*temp;

	num = n;
	len = 0;
	if (num < 0)
	{
		len = ft_digitlen(num);
		num = num * -1;
		f->is_minus = 1;
	}
	else if (num == 0)
		len = 1;
	else
		len = ft_digitlen(num);
	if (!(temp = malloc(sizeof(char) * len + 1)))
		return (0);
	temp[len] = '\0';
	while (len > 0)
	{
		temp[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (temp);
}

char	*handle_base_zero(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (2))))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_putnbr_base(unsigned long long nbr, char *base)
{
	char					*str;
	int						i;
	unsigned long long		num;

	num = nbr;
	i = 0;
	if (nbr == 0)
		return (handle_base_zero());
	while (num)
	{
		num = num / 16;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (nbr)
	{
		str[--i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}

void	init_flag(t_flag *f)
{
	f->zero = -1;
	f->minus = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_value = 0;
	f->spec = 0;
	f->is_minus = 0;
}
