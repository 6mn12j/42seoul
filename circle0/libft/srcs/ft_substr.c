/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:48:34 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/08 20:41:01 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > (unsigned int)ft_strlen(s))
		len = ft_strlen(s);
	if (!(temp = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len && s[start] && (int)start < ft_strlen(s))
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}
