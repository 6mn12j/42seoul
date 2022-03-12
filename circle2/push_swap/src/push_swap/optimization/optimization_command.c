/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 16:17:28 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_rr(t_commandlist *list)
{
	t_command	*temp;
	int			i;

	i = 0;
	temp = &(list->header_node);
	temp = temp->p_right;
	while (i < list->current_node_count)
	{
		if (ft_strncmp(temp->data, "rr", 3))
		{
			remove_command(list, i + 1);
			remove_command(list, i + 1);
		}
		temp = temp->p_right;
		i++;
	}
	return ;
}

static void	find_rr2(t_commandlist *list)
{
	t_command		*temp;
	int				here;
	int				i;

	i = 0;
	here = 0;
	temp = &(list->header_node);
	temp = temp->p_right;
	while (i < list->current_node_count)
	{
		here = i;
		if (ft_strncmp(temp->data, "ra", 3))
		{
			if (ft_strncmp(temp->p_right->data, "rb", 3))
			{
				add_command(list, here, "rr" );
				i = i + 3;
				temp = temp->p_right->p_right;
				continue ;
			}
		}
		temp = temp->p_right;
		i++;
	}
	return ;
}

static void	find_rr(t_commandlist *list)
{
	t_command		*temp;
	int				here;
	int				i;

	i = 0;
	here = 0;
	temp = &(list->header_node);
	temp = temp->p_right;
	while (i < list->current_node_count)
	{
		here = i;
		if (ft_strncmp(temp->data, "rb", 3))
		{
			if (ft_strncmp(temp->p_right->data, "ra", 3))
			{
				add_command(list, here, "rr" );
				i = i + 3;
				temp = temp->p_right->p_right;
				continue ;
			}
		}
		temp = temp->p_right;
		i++;
	}
	return ;
}

void	command_optimization(t_commandlist *list)
{
	find_rr(list);
	find_rr2(list);
	clean_rr(list);
	return ;
}
