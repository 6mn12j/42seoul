/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:44:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/30 21:47:26 by minjupar         ###   ########.fr       */
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
	// if (value<0)
	// 	l++;
	while (value)
	{
		value = value / 10;
		l++;
	}
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char		*temp;
	size_t		i;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		temp[i] = ((char*)s1)[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*temp;

	//printf("s1:%s\ns2:%s\n",s1,s2);
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(temp, s1, s1_len + 1);
	//printf("temp:%s\n",temp);
	ft_strlcpy(&temp[s1_len], s2, s2_len + 1);
	//printf("temp:%s\n",temp);
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

void	ft_strrcpy(char *dest, char const *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	//printf("\nsrc:%zu dest:%zu\n",src_len, dest_len);
	//printf("src:%s dest:%s\n",src, dest);
	i = 0;
	if (!dest || !src)
		return ;
	while (src_len >= 0 && i < size)
	{
		dest[--dest_len] = src[--src_len];
		i++;
	}
	//printf("dest:|%s|\n",dest);

	return ;
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



char	*ft_putnbr_base(long long  nbr, char *base)
{
	char *str;
	int		i;
	long long		count;

	str = base;
	i = 0;
	count = nbr;
	if (nbr == 0)
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0]='0';
		str[1]='\0';
		return (str);
	}
	while (count)
	{
		if (count == 0)
			break;
		count = count / 16;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i]='\0';
	while (i)
	{
		str[--i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}
