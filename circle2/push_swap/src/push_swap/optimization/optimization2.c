/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 16:46:02 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_five(t_all *all)
{
	int	temp;
	int	i;

	i = 0;
	while (i++ < 5)
	{
		temp = get_node(all->list_a, 0)->data;
		if (temp >= all->arr[2])
			r_ab(all, all->list_a, 'a');
		else
			p_ab(all, all->list_a, all->list_b, 'b');
	}
	handle_only_3_ta(all, 2, 4);
	handle_swap(all, 'b');
	p_ab(all, all->list_b, all->list_a, 'a');
	p_ab(all, all->list_b, all->list_a, 'a');
	return ;
}
