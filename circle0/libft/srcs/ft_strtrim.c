/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:05:09 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/08 22:35:02 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	char			*temp;

	i = 0;
	if (!s1 || !set)
		return (0);
	if (!*s1)
		return ((char*)s1);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && i < j)
		j--;
	if (i == j)
		j++;
	if (!(temp = malloc(sizeof(char) * (j - i + 1))))
		return (0);
	ft_strlcpy(temp, &s1[i], j - i + 1);
	return (temp);
}
