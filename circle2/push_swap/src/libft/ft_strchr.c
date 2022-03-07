/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/08 04:13:40 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;
	int				i;

	target = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == target)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	target;
	size_t			i;

	target = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == target)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == target)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
