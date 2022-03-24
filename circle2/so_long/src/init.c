/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 22:53:12 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_win_init(t_mlx *mlx)
{
	int		win_width;
	int		win_height;

	win_width = mlx->map_width * TILE;
	win_height = mlx->map_height * TILE;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, win_width, win_height, "mlx!");
	return ;
}

static void	img_init(t_mlx *mlx)
{
	mlx ->img_size.width = TILE;
	mlx ->img_size.height = TILE;
	mlx -> collect.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./assets/collect.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->collect.img.data = (int *)mlx_get_data_addr(mlx->collect.img.img_ptr, \
		&mlx->collect.img.bpp, &mlx->collect.img.size_l, \
			&mlx->collect.img.endian);
	mlx -> wall.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./assets/wall.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->wall.img.data = (int *)mlx_get_data_addr(mlx->wall.img.img_ptr, \
		&mlx->wall.img.bpp, &mlx->wall.img.size_l, &mlx->wall.img.endian);
	mlx -> player.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./assets/duck.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->player.img.data = (int *)mlx_get_data_addr(mlx->player.img.img_ptr, \
		&mlx->player.img.bpp, &mlx->player.img.size_l, &mlx->player.img.endian);
	mlx -> exit.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./assets/exit.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->exit.img.data = (int *)mlx_get_data_addr(mlx->exit.img.img_ptr, \
		&mlx->exit.img.bpp, &mlx->exit.img.size_l, &mlx->exit.img.endian);
	mlx -> tile.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./assets/tile.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->tile.img.data = (int *)mlx_get_data_addr(mlx->tile.img.img_ptr, \
		&mlx->tile.img.bpp, &mlx->tile.img.size_l, &mlx->tile.img.endian);
	return ;
}

static void	player_init(t_mlx *mlx)
{
	mlx->player.y = 0;
	mlx->player.x = 0;
	mlx->player.step = 0;
	mlx->player.prev = '0';
	return ;
}

static void	map_init(t_mlx *mlx)
{
	mlx->map_width = 0;
	mlx->map_height = 0;
	mlx->exit.y = 0;
	mlx->exit.x = 0;
}

void	init(t_mlx *mlx)
{
	map_init(mlx);
	img_init(mlx);
	player_init(mlx);
	return ;
}
