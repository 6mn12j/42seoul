/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/08 20:08:41 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_a_sort(t_all *all, int start_index, int end_index, char type)
{
	int	i;

	i = 0;
	if (type == 'b')
	{
		while (i++ <= end_index - start_index)
			rr_ab(all, all->list_a, 'a');
		if (i == 1 && get_node(all->list_a, 0) > get_node(all->list_a, 1))
			s_ab(all, all->list_a, 'a');
	}
	if (end_index - start_index == 0)
		return ;
	else if (end_index - start_index < 2)
		handle_swap(all, 'a');
	else if (all->list_a->current_node_count < 4)
		handle_only_three_ta(all, start_index, end_index);
	else
		handle_three_ta(all, start_index, end_index);
	return ;
}

void	top_a_to_b(t_all *all, int start_index, int end_index)
{
	int	i;
	int	temp;
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	if (end_index - start_index < 3)
		return (handle_a_sort(all, start_index, end_index, 't'));
	i = 0;
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_a, 0)->data;
		if (temp >= all->arr[big_index])
			r_ab(all, all->list_a, 'a');
		else
		{
			p_ab(all, all->list_a, all->list_b, 'b');
			if (temp < all->arr[small_index])
				r_ab(all, all->list_b, 'b');
		}
	}
	return (a_top_recur(all, start_index, end_index));
}

void	a_top_recur(t_all *all, int start_index, int end_index)
{
	int	i;
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	bottom_a_to_b(all, big_index, end_index);
	top_b_to_a(all, small_index, big_index - 1);
		i = 0;
	while (i++ <= big_index - 1 - small_index)
		p_ab(all, all->list_b, all->list_a, 'a');
	bottom_b_to_a(all, start_index, small_index - 1);
	i = 0;
	while (i++ <= small_index - 1 - start_index)
		p_ab(all, all->list_b, all->list_a, 'a');
	return ;
}

void	bottom_a_to_b(t_all *all, int start_index, int end_index)
{
	int	i;
	int	temp;
	int	small_index;
	int	big_index;

	if (all->list_a->current_node_count == end_index - start_index + 1)
	{
		top_a_to_b(all, start_index, end_index);
		return ;
	}
	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	i = 0;
	if (end_index - start_index < 3)
		return (handle_a_sort(all, start_index, end_index, 'b'));
	i = 0;
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_a, all->list_a->current_node_count - 1)->data;
		if (temp >= all->arr[big_index])
			rr_ab(all, all->list_a, 'a');
		else
		{
			rr_ab(all, all->list_a, 'a');
			p_ab(all, all->list_a, all->list_b, 'b');
			if (temp >= all->arr[small_index])
				r_ab(all, all->list_b, 'b');
		}
	}
	return (a_bottom_recur(all, start_index, end_index));
}

void	a_bottom_recur(t_all *all, int start_index, int end_index)
{
	int	i;
	int	small_index;
	int	big_index;

	i = 0;
	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	top_a_to_b(all, big_index, end_index);
	bottom_b_to_a(all, small_index, big_index - 1);
	i = 0;
	while (i++ <= big_index - 1 - small_index)
		p_ab(all, all->list_b, all->list_a, 'a');
	top_b_to_a(all, start_index, small_index - 1);
	i = 0;
	while (i++ <= small_index - 1 - start_index)
		p_ab(all, all->list_b, all->list_a, 'a');
	return ;
}
