/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 13:11:28 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/04 14:51:16 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
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
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (!dest || !src)
		return ;
	while (src_len >= 0 && i < size)
	{
		dest[--dest_len] = src[--src_len];
		i++;
	}
	return ;
}

int		my_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (1);
}

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;

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
