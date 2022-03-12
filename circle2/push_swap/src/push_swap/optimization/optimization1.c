/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 16:51:03 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_only_3_tb(t_all *all, int start_index, int end_index)
{
	int	pivot_index;

	pivot_index = start_index + 1;
	if (is_descending(all->list_b, start_index, end_index))
		return ;
	if (get_node(all->list_b, 1)->data == all->arr[pivot_index - 1])
		rr_ab(all, all->list_b, 'b');
	else if (get_node(all->list_b, 0)->data == all->arr[pivot_index - 1])
		r_ab(all, all->list_b, 'b');
	if (get_node(all->list_b, 0) < get_node(all->list_b, 1))
		s_ab(all, all->list_b, 'b');
	return ;
}

void	handle_only_3_ta(t_all *all, int start_index, int end_index)
{
	int	pivot_index;

	pivot_index = end_index - 1;
	if (is_ascending(all->list_a, start_index, end_index))
		return ;
	if (get_node(all->list_a, 0)->data > all->arr[pivot_index])
		r_ab(all, all->list_a, 'a');
	if (get_node(all->list_a, 1)->data > all->arr[pivot_index])
		rr_ab(all, all->list_a, 'a');
	if (get_node(all->list_a, 0)->data > all->arr[pivot_index - 1])
		s_ab(all, all->list_a, 'a');
	return ;
}

void	handle_three_tb(t_all *all, int start_index, int end_index)
{
	int	pivot_index;

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
	p_ab(all, all->list_b, all->list_a, 'a');
	s_ab(all, all->list_b, 'b');
	p_ab(all, all->list_a, all->list_b, 'b');
	if (is_descending(all->list_b, 0, 2))
		return ;
	s_ab(all, all->list_b, 'b');
	return ;
}

void	handle_three_ta(t_all *all, int start_index, int end_index)
{
	int	pivot_index;

	pivot_index = find_pivot(start_index, end_index, SMALL);
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

void	handle_swap(t_all *all, char target)
{
	if (target == 'a')
	{
		if (is_ascending(all->list_a, 0, all->list_a->current_node_count - 1))
			return ;
		if (get_node(all->list_a, 0)->data > get_node(all->list_a, 1)->data)
			s_ab(all, all->list_a, 'a');
		return ;
	}
	else if (target == 'b')
	{
		if (is_descending(all->list_b, 0, all->list_b->current_node_count - 1))
			return ;
		if (get_node(all->list_b, 0)->data < get_node(all->list_b, 1)->data)
			s_ab(all, all->list_b, 'b');
		return ;
	}
	return ;
}
