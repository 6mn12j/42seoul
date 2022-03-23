/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 06:48:09 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void draw_tiles(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < mlx->map_height)
	{
		col = 0;
		while (col < mlx->map_width)
		{
			if (mlx->map[row][col] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->wall.img.img_ptr, col * TILE, row *TILE);
			else
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->tile.img.img_ptr, col * TILE, row *TILE);
			if(mlx->map[row][col] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->player.img.img_ptr, col * TILE, row *TILE);
			else if (mlx->map[row][col] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->exit.img.img_ptr, col * TILE, row *TILE);
			else if (mlx->map[row][col] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->collections.img.img_ptr, col * TILE, row *TILE);
			col++;
		}
		row++;
	}
}
void	handle_draw(t_mlx *mlx)
{
	draw_tiles(mlx);
}
