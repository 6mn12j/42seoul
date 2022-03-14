/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/14 18:29:42 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	my_strlcpy(char *dest, char const *src, size_t size)
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

char	*my_strdup(const char *s1)
{
	char		*temp;
	size_t		i;
	size_t		len;

	len = my_strlen(s1);
	i = 0;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = ((char *)s1)[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*temp;

	if (!s1 && !s2)
		return (0);
	s1_len = my_strlen(s1);
	s2_len = my_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
		return (0);
	my_strlcpy(temp, s1, s1_len + 1);
	my_strlcpy(&temp[s1_len], s2, s2_len + 1);
	return (temp);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= my_strlen(s))
		return (my_strdup(""));
	if (len > my_strlen(s))
	{
		len = my_strlen(s);
		temp = (char *)malloc(sizeof(char) * (len - start + 1));
	}
	else
		temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (i < len && s[start] && start < len)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}
