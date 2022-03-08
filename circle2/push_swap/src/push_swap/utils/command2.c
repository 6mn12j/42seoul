/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/08 20:25:42 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	s_ab(t_all *all_list, t_list *t_list, char target)
{
	t_listnode	*p_firstnode;
	t_listnode	*p_secondnode;
	int			command_count;

	p_firstnode = get_node(t_list, 0);
	p_secondnode = get_node(t_list, 1);
	command_count = all_list->list_command->current_node_count;
	if (!p_firstnode || !p_secondnode)
	{
		error();
		return ;
	}
	add_element(t_list, 0, *p_secondnode);
	remove_element(t_list, 2);
	if (target == 'a')
		add_command(all_list->list_command, command_count, "sa");
	else if (target == 'b')
		add_command(all_list->list_command, command_count, "sb");
	return ;
}

void	ss(t_all *all_list, t_list *a_list, t_list *b_list, char target)
{
	int			command_count;

	command_count = all_list->list_command->current_node_count;
	s_ab(all_list, a_list, target);
	s_ab(all_list, b_list, target);
	if (target == 's')
		add_command(all_list->list_command, command_count, "ss");
	return ;
}

void	p_ab(t_all *all_list, t_list *start_list, t_list *target_list, char target)
{
	int			command_count;
	t_listnode	*p_tempnode;

	command_count = all_list->list_command->current_node_count;
	p_tempnode = get_node(start_list, 0);
	if (!p_tempnode)
		return ;
	add_element(target_list, 0,*p_tempnode);
	remove_element(start_list, 0);
	if (target == 'a')
		add_command(all_list->list_command, command_count, "pa");
	else if (target == 'b')
		add_command(all_list->list_command, command_count, "pb");
	return ;
}
