/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:00:57 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/04 23:24:38 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			str_len(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int destlen;
	unsigned int srclen;
	unsigned int result;
	unsigned int i;

	destlen = str_len(dest);
	srclen = str_len((char *)src);
	result = 0;
	i = 0;
	if (size < destlen)
		return (srclen + size);
	else
	{
		while (src[i] && destlen + i + 1 < size)
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
		return (destlen + srclen);
	}
}
