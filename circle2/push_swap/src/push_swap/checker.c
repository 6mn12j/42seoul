/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/14 18:11:41 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_command(t_all *all, char *command)
{
	if (ft_strncmp(command, "ra", 2))
		r_ab(all, all->list_a, 'a');
	else if (ft_strncmp(command, "rb", 2))
		r_ab(all, all->list_b, 'b');
	else if (ft_strncmp(command, "rra", 3))
		rr_ab(all, all->list_a, 'a');
	else if (ft_strncmp(command, "rrb", 3))
		rr_ab(all, all->list_b, 'b');
	else if (ft_strncmp(command, "sa", 2))
		s_ab(all, all->list_a, 'a');
	else if (ft_strncmp(command, "sb", 2))
		s_ab(all, all->list_b, 'b');
	else if (ft_strncmp(command, "pa", 2))
		p_ab(all, all->list_b, all->list_a, 'a');
	else if (ft_strncmp(command, "pb", 2))
		p_ab(all, all->list_a, all->list_b, 'b');
	else if (ft_strncmp(command, "ss", 2))
		ss(all, all->list_a, all->list_b, 's');
	else if (ft_strncmp(command, "rrr", 3))
		rrr(all, all->list_a, all->list_b, 'r');
	else if (ft_strncmp(command, "rr", 2))
		rr(all, all->list_a, all->list_b, 'r');
	else
		error();
	return ;
}

void	is_sorted(t_all *all)
{
	int			i;
	t_listnode	*temp;

	i = 0;
	temp = all->list_a->header_node.p_right;
	while (i < all->list_a->current_node_count)
	{
		if (temp->data != all->arr[i++])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		temp = temp->p_right;
	}
	write(1, "OK\n", 3);
	return ;
}

void	ft_checker(t_all *all)
{
	char	*command;
	int		temp;

	temp = 0;
	command = 0;
	while (1)
	{
		temp = get_next_line(0, &command);
		if (!temp)
		{
			is_sorted(all);
			return ;
		}
		else
			handle_command(all, ft_strtrim(command, "\n"));
	}
}

int	main(int argc, char *argv[])
{
	t_all	*all;
	int		i;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		error();
	init(all);
	if (argc < 2)
		error();
	i = 1;
	while (i < argc && argv[i])
		handle_argument(argv[i++], all);
	if (arr_sort_and_is_duplicate(all))
		error();
	ft_checker(all);
	exit(0);
}
