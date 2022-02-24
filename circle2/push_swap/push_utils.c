/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/24 19:53:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


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
