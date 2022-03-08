/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/09 03:46:57 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	reverse_find_pivot(int start_index, int end_index, int type)
{
	int	small_index;
	int	big_index;

	if (end_index - start_index == 0)
		return (start_index);
	if (end_index - start_index < 2)
		return (start_index + 1);
	small_index = start_index + ((end_index - start_index) + 1) / 3;
	big_index = end_index - small_index ;
	if (type == SMALL)
		return (small_index);
	else if (type == BIG)
		return (big_index);
	return (0);
}
