/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 06:47:23 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	handle_reload(t_mlx *mlx)
{
	t_player player;
	player = mlx->player;
	mlx->map[player.y][player.x] = 'P';
	mlx_clear_window(mlx->mlx_ptr,mlx->win_ptr);
	handle_draw(mlx);
}

void	move_player(t_mlx *mlx, int move_x,int move_y)
{
	t_player *player;

	player = &mlx->player;
	if (mlx->map[player->y + move_y][player->x+move_x]== '1')
			return ;
		else if(mlx->map[player->y + move_y][player->x + move_x]== 'C')
			mlx->collections.cnt--;
		else if(mlx->map[player->y + move_y][player->x+ move_x]== 'E')
		{
			if (mlx->collections.cnt == 0)
				exit(1);

		}
		mlx->map[player->y][player->x] = player->prev;

		player->y = player->y + move_y;
		player->x = player->x + move_x;
		player->prev = mlx->map[player->y][player->x];
		if (player->prev == 'C')
			player->prev = '0';
		player->step++;
		printf("%d\n",player->step);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		move_player(mlx, 0, -1);
	else if (keycode == KEY_S)
		move_player(mlx, 0, 1);
	else if (keycode == KEY_A)
		move_player(mlx, -1, 0);
	else if (keycode == KEY_D)
		move_player(mlx, 1, 0);
	else if (keycode == KEY_ESC)
		exit(0);

	handle_reload(mlx);
	return (0);
}


void	handle_read(t_mlx *mlx, char*file)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error();
	if (!get_map_width_col_valid(fd, mlx))
		not_square();
	fd = open(file, O_RDONLY);
	fill_map(mlx, fd);
	if (!valid_map(mlx))
		error();
	while (i < mlx->map_height)
		printf("%s\n", mlx->map[i++]);
	return ;
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	(void)argc;
	mlx.player.y = 0;
	mlx.player.x = 0;
	handle_read(&mlx, argv[1]);

	handle_init(&mlx);
	handle_draw(&mlx);

	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_hook, &mlx); // 키를 잡는 함수
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
