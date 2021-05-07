/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:08:43 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/08 01:18:44 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
<<<<<<< HEAD
	if (n == 0)
		return (0);
	while (i < n && (s1[i] && s2[i]))
=======
	while (i < n - 1 && s1[i] || s2[i])
>>>>>>> 125326edd3ef0a98e21ba54181eb501da3bf9498
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
<<<<<<< HEAD
	if (i == n && n != 0)
		i--;
=======
>>>>>>> 125326edd3ef0a98e21ba54181eb501da3bf9498
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
