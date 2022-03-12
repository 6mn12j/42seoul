/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/11 05:04:01 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_list *list, int start_index, int end_index)
{
	int			i;
	t_listnode	*temp_node;

	temp_node = &(list->header_node);
	i = 0;
	temp_node = temp_node->p_right;
	while (i < end_index - start_index)
	{
		if (temp_node->data > temp_node->p_right->data)
			return (0);
		temp_node = temp_node->p_right;
		i++;
	}
	return (1);
}

int	is_descending(t_list *list, int start_index, int end_index)
{
	int			i;
	t_listnode	*temp_node;

	temp_node = &(list->header_node);
	i = 0;
	temp_node = temp_node->p_right;
	while (i < end_index - start_index)
	{
		if (temp_node->data < temp_node->p_right->data)
			return (0);
		temp_node = temp_node->p_right;
		i++;
	}
	return (1);
}
