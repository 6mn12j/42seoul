/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 05:38:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_win_init(t_mlx *mlx)
{
	int		win_width;
	int		win_height;

	win_width = mlx-> map_width *TILE;
	win_height = mlx-> map_height *TILE;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, win_width, win_height, "mlx!");
	return ;
}

void	img_init(t_mlx *mlx)
{
	mlx ->img_size.width = TILE;
	mlx ->img_size.height = TILE;
	mlx -> collections.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr ,"./assets/collect.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->collections.img.data =  (int *)mlx_get_data_addr(mlx->collections.img.img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx -> wall.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/wall.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->wall.img.data =  (int *)mlx_get_data_addr(mlx->wall.img.img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx -> player.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr ,"./assets/duck.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->player.img.data =  (int *)mlx_get_data_addr(mlx->player.img.img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx -> exit.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/exit.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->exit.img.data =  (int *)mlx_get_data_addr(mlx->exit.img.img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx -> tile.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/tile.xpm", &mlx->img_size.width, &mlx->img_size.height);
	mlx ->tile.img.data =  (int *)mlx_get_data_addr(mlx->tile.img.img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);

	return ;
}

void player_init(t_mlx *mlx)
{
	mlx->player.step = 0;
	mlx->player.prev='0';
	return ;
}

void	handle_init(t_mlx *mlx)
{

	mlx_win_init(mlx);
	img_init(mlx);
	player_init(mlx);
	return ;
}
