/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:05:09 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/08 06:45:34 by minjupar         ###   ########.fr       */
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
	j = ft_strlen(s1);

	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j] && ft_strrchr(set, s1[j]) && i < j)
		j--;

	if (i == j)
		j++;
		printf("%zu set: %s!\n",j,set);
	if (!(temp = malloc(sizeof(char) * (j - i + 1))))
		return (0);
	ft_memmove(temp, &s1[i], j - i);
	return (temp);
}
 int		main(void)
{
	printf("%s",ft_strtrim(" aa v  "," "));
}