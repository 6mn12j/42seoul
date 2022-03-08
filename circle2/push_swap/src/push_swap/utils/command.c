/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/08 20:21:42 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_ab(t_all *all_list, t_list *t_list, char target)
{
	t_listnode	*temp;
	int			i;
	int			command_count;

	command_count = all_list->list_command->current_node_count;
	i = 0;
	temp = &(t_list->header_node);
	temp = temp -> p_right;
	add_element(t_list, t_list->current_node_count, *temp);
	remove_element(t_list, 0);
	if (target == 'a')
		add_command(all_list->list_command, command_count, "ra");
	else if (target == 'b')
		add_command(all_list->list_command, command_count, "rb");
	return ;
}

void	rr(t_all *all_list, t_list *a_list, t_list *b_list, char target)
{
	int			command_count;

	command_count = all_list->list_command->current_node_count;
	r_ab(all_list, a_list, target);
	r_ab(all_list, b_list, target);
	if (target == 'r')
		add_command(all_list->list_command, command_count, "rr");
	return ;
}
//마지막 원소는 첫번째 원소가 된다.

void	rr_ab(t_all *all_list, t_list *t_list, char target)
{
	t_listnode	*temp;
	int			i;
	int			command_count;

	command_count = all_list->list_command->current_node_count;
	i = 0;
	temp = &(t_list->header_node);
	temp = temp -> p_left;
	add_element(t_list, 0, *temp);
	remove_element(t_list, t_list -> current_node_count - 1);
	if (target == 'a')
		add_command(all_list->list_command, command_count, "rra");
	else if (target == 'b')
		add_command(all_list->list_command, command_count, "rrb");
	return ;
}

void	rrr(t_all *all_list, t_list *a_list, t_list *b_list,char target)
{
	int			command_count;

	command_count = all_list->list_command->current_node_count;
	rr_ab(all_list, a_list, target);
	rr_ab(all_list, b_list, target);
	if (target == 'r')
		add_command(all_list->list_command, command_count, "rrr");
	return ;
}
