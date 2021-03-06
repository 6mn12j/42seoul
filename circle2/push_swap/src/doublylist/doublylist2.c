/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 21:47:51 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_element(t_list *p_list, int position, t_listnode element)
{
	t_listnode	*p_new_node;
	t_listnode	*temp_node;
	int			i;

	if (!p_list || position < 0 || p_list -> current_node_count < position)
		return (0);
	p_new_node = (t_listnode *)malloc(sizeof(t_listnode));
	if (!p_new_node)
		error();
	temp_node = &(p_list->header_node);
	p_new_node->data = element.data;
	i = 0;
	while (i < position)
	{
		temp_node = temp_node->p_right;
		i++;
	}
	p_new_node->p_left = temp_node;
	p_new_node->p_right = temp_node->p_right;
	temp_node->p_right = p_new_node;
	p_new_node->p_right->p_left = p_new_node;
	p_list->current_node_count++;
	return (1);
}

t_list	*create_list(void)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		error();
	new_list->header_node.p_right = &new_list->header_node;
	new_list->header_node.p_left = &new_list->header_node;
	new_list->current_node_count = 0 ;
	return (new_list);
}

t_listnode	*make_list_node(int data)
{
	t_listnode	*listnode;

	listnode = (t_listnode *)malloc(sizeof(t_listnode));
	if (!listnode)
		error();
	else
	{
		listnode->data = data;
		listnode->p_left = 0;
		listnode->p_right = 0;
	}
	return (listnode);
}
