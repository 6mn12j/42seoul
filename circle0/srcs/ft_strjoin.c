/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:10:50 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/07 19:36:17 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*temp;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(temp = (char *)malloc(sizeof(char) * s1_len + s2_len + 1)))
		return (0);
	temp = ft_memcpy(temp, s1, s1_len);
	ft_memcpy(temp + s1_len, s2, s2_len + 1);
	temp[s1_len + s2_len] = '\0';
	return (temp);
}
