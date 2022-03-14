/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/14 17:30:19 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"




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
	start_push_swap(all);
	command_optimization(all->list_command);
	display_command(all->list_command);
	exit (0);
}
