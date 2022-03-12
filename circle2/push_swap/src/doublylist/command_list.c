/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 20:42:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_command(t_commandlist *p_list, int position, char *element)
{
	t_command	*p_new_node;
	t_command	*temp_node;
	int			i;

	if (!p_list || position < 0 || p_list -> current_node_count < position)
		error();
	p_new_node = (t_command *)malloc(sizeof(t_command));
	if (!p_new_node)
		error();
	temp_node = &(p_list->header_node);
	p_new_node->data = element;
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
	return (0);
}

t_commandlist	*create_command_list(void)
{
	t_commandlist	*new_list;

	new_list = (t_commandlist *)malloc(sizeof(t_commandlist));
	if (!new_list)
		error();
	new_list->header_node.p_right = &new_list->header_node;
	new_list->header_node.p_left = &new_list->header_node;
	new_list->current_node_count = 0 ;
	return (new_list);
}

void	display_command(t_commandlist *pList)
{
	t_command	*temp_node;
	char		newline;
	int			i;

	i = 0;
	newline = 'n';
	if (pList -> current_node_count == 0)
		return ;
	temp_node = &(pList->header_node);
	while (i < pList -> current_node_count)
	{
		temp_node = temp_node->p_right ;
		ft_putstr_fd(temp_node -> data, 1);
		write(1, "\n", 1);
		i++;
	}
}
