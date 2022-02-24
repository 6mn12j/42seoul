/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/25 02:35:52 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void init(t_all *all_list)
{
	t_list *list_a;
	t_list *list_b;

	all_list->arr=0;
	list_a = create_list();
	list_b = create_list();
	all_list->list_a = list_a;
	all_list->list_b = list_b;
	return ;
}



int main(int argc, char *argv[])
{
	t_all  *all;

	all = (t_all *)malloc(sizeof(t_all));
	init(all);
	int i = 1;

	while (i < argc && argv[i])
		handle_argument(argv[i++], all->list_a);
	printf("lista count%d: ",all->list_a->current_element_count);
	display(all->list_a);
	s_ab(all->list_a);
	display(all->list_a);

	printf("all lista count%d: ",all->list_a->current_element_count);
	display(all->list_a);

	// display(list_b);
	// p_ab(list_a,list_b);
	// display(list_a);
	// display(list_b);
	// printf("a1\n");
	// printf("asb2\n");
	// display(list_a);
	// r_ab(list_a);
	// display(list_a);
	// rr_ab(list_a);
	// display(list_a);

	// system("leaks a.out");
}
