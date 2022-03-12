/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 03:25:58 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_bottom_recur(t_all *all, int start_index, int end_index)
{
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	top_a_to_b(all, big_index, end_index);
	bottom_a_to_b(all, small_index, big_index - 1);
	top_b_to_a(all, start_index, small_index -1);
	return ;
}
