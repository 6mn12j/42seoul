/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/07 03:04:35 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_three_tb(t_all *all, int start_index, int end_index)
{
	printf("handle_three_tb\n");
	int pivot_index;

	pivot_index = find_pivot(start_index, end_index, SMALL);
	if (is_descending(all->list_b, 0, 2))
		return ;
	if (get_node(all->list_b, 2)->data == all->arr[pivot_index - 1])
	{
		s_ab(all, all->list_b, 'b');
		return ;
	}
	if (get_node(all->list_b, 0)->data == all->arr[pivot_index - 1])
		s_ab(all, all->list_b, 'b');
	p_ab(all, all->list_b, all->list_a, 'b');
	s_ab(all, all->list_b, 'b');
	p_ab(all, all->list_a, all->list_b, 'b');
	if (is_descending(all->list_b, 0, 2))
		return ;
	s_ab(all, all->list_b, 'b');
	//내림차순 정렬
	return ;
}


void	handle_three_ta(t_all *all, int start_index, int end_index)
{
	printf("handle_three_ta\n");
	int pivot_index;

	pivot_index = find_pivot(start_index, end_index, SMALL);
	printf("pivot%d\n",pivot_index);
	if (is_ascending(all->list_a, 0, 2))
		return ;
	if (get_node(all->list_a, 2)->data == all->arr[pivot_index + 1])
	{
		s_ab(all, all->list_a, 'a');
		return ;
	}
	if (get_node(all->list_a, 0)->data == all->arr[pivot_index + 1])
		s_ab(all, all->list_a, 'a');
	p_ab(all, all->list_a, all->list_b, 'b');
	s_ab(all, all->list_a, 'a');
	p_ab(all, all->list_b, all->list_a, 'a');
	if (is_ascending(all->list_a, 0, 2))
		return ;
	s_ab(all, all->list_a, 'a');
	return ;
}
