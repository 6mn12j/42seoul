/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/27 04:10:44 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_ab(t_list *t_list)
{
	t_listnode	*temp;
	int			i;

	i = 0;
	temp = &(t_list->header_node);
	temp = temp -> p_right;
	add_element(t_list, t_list->current_element_count, *temp);
	remove_element(t_list, 0);
	return ;
}

void	rr(t_list *a_list, t_list *b_list)
{
	r_ab(a_list);
	r_ab(b_list);
	return ;
}
//마지막 원소는 첫번째 원소가 된다.

void	rr_ab(t_list *t_list)
{
	t_listnode	*temp;
	int			i;

	i = 0;
	temp = &(t_list->header_node);
	temp = temp -> p_left;
	add_element(t_list, 0, *temp);
	remove_element(t_list, t_list -> current_element_count - 1);
	return ;
}

void	rrr(t_list *a_list, t_list *b_list)
{
	rr_ab(a_list);
	rr_ab(b_list);
	return ;
}
