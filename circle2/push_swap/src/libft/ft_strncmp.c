/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:08:43 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 04:11:05 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (i < n)
	{
		if ((i == 3 && s1[i] == 'b')
			|| ((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (0);
		i++;
	}
	return (1);
}
