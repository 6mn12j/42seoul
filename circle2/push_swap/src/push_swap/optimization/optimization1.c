/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/07 22:18:19 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_three_tb(t_all *all, int start_index, int end_index)
{
	int pivot_index;
printf("handle_three_tb\n");
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
	int pivot_index;
	printf("handle_three_ta\n");
	pivot_index = find_pivot(start_index, end_index, SMALL);
	if (is_ascending(all->list_a, 0, 2))
		return ;
	if (get_node(all->list_a, 2)->data == all->arr[pivot_index + 1])
	{ //1 !== 3 여기안들어옴
		s_ab(all, all->list_a, 'a');
		return ;
	}
	if (get_node(all->list_a, 0)->data == all->arr[pivot_index + 1])
		s_ab(all, all->list_a, 'a'); //3 == 3 여기 들어옴
		//231
	p_ab(all, all->list_a, all->list_b, 'b'); //2        31
	s_ab(all, all->list_a, 'a');// 2      13
	p_ab(all, all->list_b, all->list_a, 'a');// 2 1 3
	if (is_ascending(all->list_a, 0, 2))
		return ;
	s_ab(all, all->list_a, 'a'); // 1 2 3
	return ;
}
