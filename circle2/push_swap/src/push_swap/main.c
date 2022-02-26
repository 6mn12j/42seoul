/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/27 04:07:29 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void init(t_all *all_list)
{
	t_list *list_a;
	t_list *list_b;

	all_list->arr = 0;
	list_a = create_list();
	list_b = create_list();
	all_list->list_a = list_a;
	all_list->list_b = list_b;
	return ;
}

// void sort_target_list(t_all *all_list)
// {
// 	int i;
// 	int j;
// 	int temp;
// 	int max_length;
// 	t_listnode *p_temp;

// 	i = 0;
// 	j = 0;
// 	max_length = all_list->list_a->current_element_count;
// 	all_list->arr = (int *)malloc(sizeof(int ) * max_length);
// 	p_temp = &(all_list -> list_a->header_node);
// 	while (i < max_length)
// 	{
// 		p_temp = p_temp->p_right;
// 		all_list->arr[i++] = p_temp->data;
// 	}
// 	while (i < max_length)
//     {
// 		while (j < max_length - 1 )
//         {
// 			//// 현재 요소의 값과 다음 요소의 값을 비교하여
//             if (all_list->arr[j] > all_list->arr[j + 1])
//             {                                 // 큰 값을
//                 temp = all_list->arr[j];
//                 all_list->arr[j] = all_list->arr[j + 1];
//                 all_list->arr[j + 1] = temp;            // 다음 요소로 보냄
//             }
//         }
//     }
// 	return ;
// }

int main(int argc, char *argv[])
{
	t_all  *all;

	all = (t_all *)malloc(sizeof(t_all));
	init(all);
	int i = 1;

	while (i < argc && argv[i])
		handle_argument(argv[i++], all);
//	sort_target_list(all);
		//printf("target\n");

	// for (int k = 0 ; k < all -> list_a -> current_element_count ; k++)
	// 	printf("%d\n", all->arr[i]);

	//printf("lista count%d: ",all->list_a->current_element_count);
	display_list(all->list_a);
	// s_ab(all->list_a);
	// display_list(all->list_a);

	// printf("all lista count%d: ",all->list_a->current_element_count);
	// display_list(all->list_a);
	// display_list(list_b);
	// p_ab(list_a,list_b);
	// display_list(list_a);
	// display_list(list_b);
	// printf("a1\n");
	// printf("asb2\n");
	// display_list(list_a);
	// r_ab(list_a);
	// display_list(list_a);
	// rr_ab(list_a);
	// display_list(list_a);

	// system("leaks a.out");
}
