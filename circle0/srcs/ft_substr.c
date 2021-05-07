/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:48:34 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/07 18:09:12 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len && s[start])
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	return (temp);
}
