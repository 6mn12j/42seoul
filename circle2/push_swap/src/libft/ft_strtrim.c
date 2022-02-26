/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/27 05:18:29 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static char	*ft_strdup(const char *s1)
{
	char		*temp;
	size_t		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!temp)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		temp[i] = ((char *)s1)[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

static size_t	ft_strlcpy(char *dest, char const *src, size_t size)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	char			*temp;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup((char *)s1));
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && i < j - 1)
		j--;
	if (!(temp = malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	ft_strlcpy(temp, &s1[i], j - i + 1);
	return (temp);
}
