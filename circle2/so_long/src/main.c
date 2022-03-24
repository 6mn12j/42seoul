/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 22:32:03 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_mlx *mlx)
{
	printf("END\n");
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		handle_error(NOT_ARGUMENT);
	init(&mlx);
	open_map_file(&mlx, argv[1]);
	mlx_win_init(&mlx);
	fill_map(&mlx);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0, close_game, &mlx);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	system("leaks so_long > leaks_result_temp; cat leaks_result_temp | grep leaked");
	return (0);
}
