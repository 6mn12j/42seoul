/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 00:25:16 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/09 02:23:10 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**split_free(char **temp)
{
	size_t	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (0);
}

char	**split_malloc(char **temp, char const *src, char c, size_t wc)
{
	size_t	i;
	size_t	start;
	size_t	count;

	count = 0;
	i = 0;
	start = 0;
	while (src[i] && count < wc)
	{
		if (src[i] != c)
		{
			start = i;
			while (src[i] && src[i] != c)
				i++;
			if (!(temp[count] = malloc(sizeof(char) * (i - start + 1))))
				return (split_free(temp));
			temp[count++] = ft_substr(src, start, i - start);
		}
		else
			i++;
	}
	temp[count] = 0;
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	char	**temp;

	i = 0;
	wc = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	if (!(temp = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (0);
	return (split_malloc(temp, s, c, wc));
}
