/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/07 15:20:26 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void init(t_all *all_list)
{
	t_list *list_a;
	t_list *list_b;
	t_commandlist *list_command;

	all_list->arr = 0;
	list_a = create_list();
	list_b = create_list();
	list_command = create_command_list();
	all_list->list_a = list_a;
	all_list->list_b = list_b;
	all_list->list_command = list_command;
	return ;
}


void	bubble_sort(int *arr, int cnt)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int arr_sort_duplicate(t_all *all)
{
	t_listnode *temp;
	int i;
	i = 0;
	temp = &(all->list_a->header_node);
	all->arr = (int *)malloc(sizeof(int) * all->list_a->current_node_count);
	while (i < all->list_a->current_node_count)
	{
		temp = temp->p_right;
		all->arr[i++] = temp->data;
	}
	bubble_sort(all->arr, all->list_a->current_node_count);
	i = 0;
	while (i < all->list_a->current_node_count - 1){
        if (all->arr[i] == all->arr[i+1])
			return 1;
		i++;
    }
	return (0);
}

void start_push_swap(t_all *all)
{
	if (arr_sort_duplicate(all))
		error();
	for(int i = 0 ;i < all->list_a->current_node_count;i++)
			printf("%d ",all->arr[i]);
	if (all->list_a->current_node_count < 3)
		handle_swap(all, 'a');
	else
		tA_to_B(all, 0, all->list_a->current_node_count-1);

}


int main(int argc, char *argv[])
{
	t_all  *all;

	all = (t_all *)malloc(sizeof(t_all));
	init(all);
	int i = 1;

	while (i < argc && argv[i])
		handle_argument(argv[i++], all);
	start_push_swap(all);
	display_list(all->list_a);
	display_list(all->list_b);

	// system("leaks a.out");
}
