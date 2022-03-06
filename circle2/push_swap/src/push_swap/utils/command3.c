/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/06 18:52:14 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(int start_index, int end_index, int type)
{
	int	small_index;
	int	big_index;
	if (end_index - start_index < 2)
		return (start_index + 1);
	small_index = start_index + ((end_index - start_index) + 1) / 3;
	big_index =  ((end_index - small_index + 1) / 2) + small_index ;
	printf("pivot index: %d %d\n",small_index, big_index);
	if (type == SMALL)
		return (small_index);
	else if (type == BIG)
		return (big_index);
	return (0);
}


void	handle_three_tb(t_all *all, int start_index, int end_index)
{
	printf("handle_three_tb\n");
	int pivot_index;

	pivot_index = find_pivot(start_index, end_index, SMALL);
	if (is_descending(all->list_b, 0, 2))
		return ;
	if (get_node(all->list_b, 2)->data == all->arr[pivot_index - 1])
	{
		s_ab(all, all->list_b, 'b');
		return ;
	}
	if (get_node(all->list_b, 0)->data == all->arr[pivot_index - 1])
		s_ab(all, all->list_b, 'b');
	p_ab(all, all->list_b, all->list_a, 'b');
	s_ab(all, all->list_b, 'b');
	p_ab(all, all->list_a, all->list_b, 'b');
	if (is_descending(all->list_b, 0, 2))
		return ;
	s_ab(all, all->list_b, 'b');
	//내림차순 정렬
	return ;
}

void	handle_three_ta(t_all *all, int start_index, int end_index)
{
	printf("handle_three_ta\n");
	int pivot_index;

	pivot_index = find_pivot(start_index, end_index, SMALL);
	printf("pivot%d\n",pivot_index);
	if (is_ascending(all->list_a, 0, 2))
		return ;
	if (get_node(all->list_a, 2)->data == all->arr[pivot_index + 1])
	{
		s_ab(all, all->list_a, 'a');
		return ;
	}
	if (get_node(all->list_a,0)->data == all->arr[pivot_index + 1])
		s_ab(all, all->list_a, 'a');
	p_ab(all, all->list_a, all->list_b, 'b');
	s_ab(all, all->list_a, 'a');
	p_ab(all, all->list_b, all->list_a, 'a');
	if (is_ascending(all->list_a, 0, 2))
		return ;
	s_ab(all, all->list_a, 'a');
	return ;
}

void	tA_to_B(t_all *all, int start_index, int end_index)
{
	printf("tA_to_B:%d %d\n",start_index,end_index);
	int	i;
	int temp;
	int small_index;
	int big_index;

	small_index = find_pivot( start_index, end_index, SMALL);
	big_index = find_pivot( start_index, end_index, BIG);
	printf("here small:%d big:%d\n",small_index,big_index);
	if (end_index - start_index < 3)
	{
		if(end_index - start_index < 2)
			handle_swap(all, 'a');
		else
			handle_three_ta(all, start_index, end_index);
		return ;
	}
	i = 0;
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_a, 0)->data;
		if (temp >= all->arr[big_index])
			r_ab(all, all->list_a, 'a');
		else
		{
			p_ab(all, all->list_a, all->list_b, 'b');
			if (temp < all->arr[small_index])
				r_ab(all, all->list_b, 'b');
		}
	}
	display_list(all->list_a);
	display_list(all->list_b);
	bA_to_B(all, big_index, end_index);
	display_list(all->list_a);
	display_list(all->list_b);
	tB_to_A(all, small_index, big_index - 1);
	display_list(all->list_a);
	display_list(all->list_b);
	bB_to_A(all, start_index, small_index - 1);
	return ;
}

void	bA_to_B(t_all *all, int start_index, int end_index)
{
	printf("bA_to_B:%d %d\n",start_index, end_index);
	int	i;
	int temp;
	int small_index;
	int big_index;

	small_index = find_pivot( start_index, end_index, SMALL);
	big_index = find_pivot( start_index, end_index, BIG);
	if (end_index - start_index < 3)
	{
		if (all->list_a->current_node_count > 3)
			rr_ab(all, all->list_a, 'a');
		if(end_index - start_index == 1)
			handle_swap(all, 'a');
		else
			handle_three_ta(all, start_index, end_index);
		return ;
	}
	i = 0;
	while (i++ <=  end_index - start_index)
	{
		temp = get_node(all->list_a, all->list_a->current_node_count - 1)->data;
		if (temp >= all->arr[big_index])
			rr_ab(all, all->list_a, 'a'); //rra

		else
		{
			rr_ab(all, all->list_a, 'a'); //rra
			p_ab(all, all->list_a, all->list_b, 'b');
			if (temp < all->arr[small_index])
				r_ab(all, all->list_b, 'b');


		}
	}
	display_list(all->list_a);
	display_list(all->list_b);
	tA_to_B(all, big_index, end_index);
	display_list(all->list_a);
	display_list(all->list_b);
	tB_to_A(all, small_index, big_index - 1);
	display_list(all->list_a);
	display_list(all->list_b);
	bB_to_A(all, start_index, small_index - 1);
	return ;
}

void	tB_to_A(t_all *all, int start_index, int end_index)
{
	int	i;
	int temp;
	int small_index;
	int big_index;
	printf("tB_to_A:%d %d\n",start_index,end_index);
	i = 0;
	small_index = find_pivot( start_index, end_index, SMALL);
	big_index = find_pivot( start_index, end_index, BIG);
	if (end_index - start_index < 3)
	{
		if (end_index == 0)
			return (p_ab(all, all->list_b, all->list_a, 'a'));
		if (end_index - start_index == 1)
			handle_swap(all, 'b');
		else
			handle_three_tb(all, start_index, end_index);
		display_list(all->list_a);
		display_list(all->list_b);

		while(i++ <= end_index - start_index )
			p_ab(all, all->list_b, all->list_a, 'a');
		return ;
	}
	while (i++ <= end_index - start_index)
	{
		temp = get_node(all->list_a, 0)->data;
		if (temp >= all->arr[big_index])
			r_ab(all, all->list_b, 'b');
		else
		{
			p_ab(all, all->list_b, all->list_a, 'a'); //pa
			if ( temp < all->arr[small_index])
				r_ab(all, all->list_a, 'a');
		}
	}
	display_list(all->list_a);
	display_list(all->list_b);
	bB_to_A(all, big_index, end_index);
	display_list(all->list_a);
	display_list(all->list_b);
	bA_to_B(all, small_index, big_index);
	display_list(all->list_a);
	display_list(all->list_b);
	tA_to_B(all, start_index, small_index - 1);
	return ;
}

void	bB_to_A(t_all *all, int start_index, int end_index)
{
	printf("bB_toA:%d %d\n",start_index,end_index);
	int	i;
	int	temp;
	int	small_index;
	int	big_index;

	i = 0;
	small_index = find_pivot(start_index, end_index, SMALL);
	big_index = find_pivot(start_index, end_index, BIG);
	if (end_index - start_index < 3)
	{
		while (i++ <= end_index - start_index)
		{
			rr_ab(all, all->list_b,'b');
		}
		if (end_index == 0)
			return (p_ab(all, all->list_b, all->list_a, 'a'));

		i = 0;
		if (end_index - start_index == 1)
			handle_swap(all, 'b');
		else
			handle_three_tb(all, start_index, end_index);
		while (i++ <= end_index - start_index )
			p_ab(all, all->list_b, all->list_a, 'a');
		return ;
	}
	while (i++ <= end_index - start_index)
	{
	temp = get_node(all->list_a, all->list_b->current_node_count - 1)->data;
		if (temp > all->arr[big_index])
			rr_ab(all, all->list_b, 'b'); //rrb
		else
		{
			rr_ab(all, all->list_b, 'b'); //rrb
			p_ab(all, all->list_b, all->list_a, 'a'); //pa
			if ( temp > all->arr[small_index])
				r_ab(all, all->list_a, 'a');
		}
	}
	tB_to_A(all, big_index, end_index);
	display_list(all->list_a);
	display_list(all->list_b);
	bA_to_B(all, small_index, big_index);
	display_list(all->list_a);
	display_list(all->list_b);
	tA_to_B(all, start_index, small_index-1);
	return ;
}


int is_ascending(t_list *list, int start_index, int end_index)
{
	int			i;
	t_listnode	*temp_node;

	i = 0;
	temp_node = &(list->header_node);
	while (i++ < start_index)
		temp_node = temp_node->p_right;
	i = 0;
	while (i < end_index-start_index )
	{
		temp_node = temp_node->p_right;
		printf("a:%d %d\n",temp_node->data,temp_node->p_right->data);
		if (temp_node->data > temp_node->p_right->data)
			return (0);
		i++;
	}
	return (1);
}

int is_descending(t_list *list,int start_index, int end_index)
{
	int			i;
	t_listnode	*temp_node;

	i = 0;
	temp_node = &(list->header_node);
	while (i++ < start_index && temp_node->p_right->data)
		temp_node = temp_node->p_right;
	i = start_index;
	while (i < end_index-start_index )
	{
		temp_node = temp_node->p_right;
		if (temp_node->data < temp_node->p_right->data)
			return (0);
		i++;
	}
	return (1);
}

void	handle_swap(t_all *all, char target)
{
	printf("handle swap\n");
	if (target == 'a')
	{
		if(is_ascending(all->list_a, 0, all->list_a->current_node_count - 1))
		{	printf("hehre\n");
			return;
		}
		if (get_node(all->list_a, 0)->data > get_node(all->list_a, 1)->data)
			s_ab(all, all->list_a, 'a');
		return ;
	}
	else if (target == 'b')
	{
		if(is_descending(all->list_b, 0 ,all->list_b->current_node_count - 1))
			return;
		if (get_node(all->list_b, 0)->data < get_node(all->list_b, 1)->data)
			s_ab(all, all->list_b, 'b');
		return ;
	}
	return ;
}
