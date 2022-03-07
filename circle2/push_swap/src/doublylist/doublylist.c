/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/23 19:25:20 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listnode	*get_node(t_list *p_list, int position)
{
	t_listnode	*temp_node;
	int			i;

	i = 0;
	if (position >= p_list->current_node_count)
		return (0);
	temp_node = &(p_list->header_node);
	while (i <= position)
	{
		temp_node = temp_node->p_right;
		i++;
	}
	return (temp_node);
}

void	deletet_list(t_list *p_list)
{
	cleart_list(p_list);
	free(p_list);
	p_list = 0;
	return ;
}

void	cleart_list(t_list *p_list)
{
	t_listnode	*p_del_node;
	t_listnode	*temp_node;
	int			i;

	i = 0;
	if (!p_list)
		return ;
	temp_node = p_list->header_node.p_left;
	while (i < p_list->current_node_count)
	{
		p_del_node = temp_node;
		temp_node = temp_node->p_left;
		free(p_del_node);
		p_del_node = 0;
		i++;
	}
	p_list->header_node.p_right = &p_list->header_node;
	p_list->header_node.p_left = &p_list->header_node;
	p_list->current_node_count = 0;
	return ;
}

int	remove_element(t_list *p_list, int position)
{
	t_listnode	*temp_node;
	t_listnode	*p_del_node;
	int			i;

	if (!p_list || position < 0 || p_list -> current_node_count < position)
		return (-1);
	temp_node = &(p_list->header_node);
	i = 0;
	while (i++ < position)
		temp_node = temp_node->p_right;
	p_del_node = temp_node->p_right;
	temp_node->p_right = p_del_node->p_right;
	temp_node->p_right->p_left = temp_node;
	free(p_del_node);
	p_del_node = 0;
	p_list -> current_node_count--;
	return (1);
}

int	get_list_length(t_list *p_list)
{
	return (p_list->current_node_count);
}
