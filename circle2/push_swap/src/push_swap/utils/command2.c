/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/24 00:25:15 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	s_ab(t_list *t_list)
{
	t_listnode	*p_firstnode;
	t_listnode	*p_secondnode;

	p_firstnode = get_element(t_list, 0);
	p_secondnode = get_element(t_list, 1);
	if (!p_firstnode || !p_secondnode)
	{
		printf("error\n");
		return ;
	}
	add_element(t_list, 0, *p_secondnode);
	remove_element(t_list, 2);
	return ;
}

void	ss(t_list *a_list, t_list *b_list)
{
	s_ab(a_list);
	s_ab(b_list);
	return ;
}

void	p_ab(t_list *start_list, t_list *target_list)
{
	t_listnode	*p_tempnode;

	p_tempnode = get_element(start_list, 0);
	if (!p_tempnode)
		return ;
	add_element(target_list, 0,*p_tempnode);
	remove_element(start_list, 0);
	return ;
}
