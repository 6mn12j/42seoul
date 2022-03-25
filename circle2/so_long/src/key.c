/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/25 16:15:04 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_player(t_mlx *mlx, int move_x, int move_y)
{
	t_player	*player;

	player = &mlx->player;
	if (mlx->map[player->y + move_y][player->x + move_x] == '1')
		return ;
	else if (mlx->map[player->y + move_y][player->x + move_x] == 'C')
		mlx->collect.cnt--;
	else if (mlx->map[player->y + move_y][player->x + move_x] == 'E')
	{
		if (mlx->collect.cnt == 0)
			close_game(mlx);
	}
	mlx->map[player->y][player->x] = player->prev;
	player->y = player->y + move_y;
	player->x = player->x + move_x;
	player->prev = mlx->map[player->y][player->x];
	if (player->prev == 'C')
		player->prev = '0';
	player->step++;
	printf("%d\n", player->step);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		move_player(mlx, 0, -1);
	else if (keycode == KEY_S)
		move_player(mlx, 0, 1);
	else if (keycode == KEY_A)
		move_player(mlx, -1, 0);
	else if (keycode == KEY_D)
		move_player(mlx, 1, 0);
	else if (keycode == KEY_ESC || keycode == 17)
		close_game(mlx);
	re_fillmap(mlx);
	return (0);
}
