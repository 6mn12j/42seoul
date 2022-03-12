/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 04:33:25 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* type -b(bottom) -t(top)
**/
static void	handle_bottom(t_all *all, int start_index, int end_index)
{
	int	i;

	i = 0;
	while (i++ <= end_index - start_index)
		rr_ab(all, all->list_b, 'b');
	if (i == 1 && get_node(all->list_b, 0) > get_node(all->list_b, 1))
		s_ab(all, all->list_b, 'b');
}
static void	handle_b_fin(t_all *all, int start_index, int end_index, char type)
{
	int	i;

	i = 0;
	if (type == 'b')
		handle_bottom(all, start_index, end_index);
	if (end_index == start_index)
	{
		p_ab(all, all->list_b, all->list_a, 'a');
		return ;
	}
	else if (end_index - start_index == 1)
	{
		handle_swap(all, 'b');
		p_ab(all, all->list_b, all->list_a, 'a');
		p_ab(all, all->list_b, all->list_a, 'a');
		return ;
	}
	else
		handle_three_tb(all, start_index, end_index);
	p_ab(all, all->list_b, all->list_a, 'a');
	p_ab(all, all->list_b, all->list_a, 'a');
	p_ab(all, all->list_b, all->list_a, 'a');
	return ;
}


/* A 3a2 B b1
** 3 2 1
*/
void	top_b_to_a(t_all *all, int start_index, int end_index)
{
	int	i;
	int	temp;
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	if (end_index - start_index < 3)
		return (handle_b_fin(all, start_index, end_index, 't'));
	i = 0;
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_b, 0)->data;
		if (temp < all->arr[small_index])
			r_ab(all, all->list_b, 'b');
		else
		{
			p_ab(all, all->list_b, all->list_a, 'a');
			if (temp < all->arr[big_index])
				r_ab(all, all->list_a, 'a');
		}
	}
	return (b_top_recur(all, start_index, end_index));
}

void	b_top_recur(t_all *all, int start_index, int end_index)
{
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	top_a_to_b(all, big_index, end_index);
	bottom_a_to_b(all, small_index, big_index - 1);
	bottom_b_to_a(all, start_index, small_index - 1);
	return ;
}

/*A 3a2 B 1b
** 3 2 1
*/
void	bottom_b_to_a(t_all *all, int start_index, int end_index)
{
	int	i;
	int	temp;
	int	small_index;
	int	big_index;

	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	i = 0;
	if (end_index - start_index < 3)
		return (handle_b_fin(all, start_index, end_index, 'b'));
	i = 0;
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_b, all->list_b->current_node_count - 1)->data;
		rr_ab(all, all->list_b, 'b');
		if (temp >= all->arr[small_index])
		{
			p_ab(all, all->list_b, all->list_a, 'a');
			if (temp < all->arr[big_index])
				r_ab(all, all->list_a, 'a');
		}
	}
	return (b_bottom_recur(all, start_index, end_index));
}
