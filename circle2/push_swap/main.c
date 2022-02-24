/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/24 19:56:16 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int main(int argc, char *argv[])
{
	//더블리리스트를 2개 만들어서
	// a 에 받은 숫자들을 다 넣어주고
	t_all  *all;
	t_list *list_a;
	t_list *list_b;

	all = (t_all *)malloc(sizeof(t_all));
	list_a = create_list();
	list_b = create_list();
	all->a_list = list_a;
	all->b_list = list_b;
	int i = 1;

	while (argv[i])
	{
		if(valid_input(argv[i],list_a))
		{
			//printf("%s ",argv[i]);
		}
		else{
			printf("not valid Error\n");
			return (-1);
		}
		i++;
	}
	printf("lista count%d: ",list_a->current_element_count);
	display(list_a);
	printf("all lista count%d: ",all->a_list->current_element_count);
	display(all->a_list);

	display(list_b);
	p_ab(list_a,list_b);
	display(list_a);
	display(list_b);
	printf("a1\n");
	s_ab(list_a);
	printf("asb2\n");
	display(list_a);
	r_ab(list_a);
	display(list_a);
	rr_ab(list_a);
	display(list_a);

	// system("leaks a.out");
}
