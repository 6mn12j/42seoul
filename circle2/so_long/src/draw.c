/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/25 16:32:27 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_put_img_win(t_mlx *mlx, void *imp_ptr, int col, int row)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
									imp_ptr, col * TILE, row * TILE);
	return ;
}

void	fill_map(t_mlx *mlx)
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
				ft_put_img_win(mlx, mlx->wall.img.img_ptr, col, row);
			else
				ft_put_img_win(mlx, mlx->tile.img.img_ptr, col, row);
			if (mlx->map[row][col] == 'P')
				ft_put_img_win(mlx, mlx->player.img.img_ptr, col, row);
			else if (mlx->map[row][col] == 'E')
				ft_put_img_win(mlx, mlx->exit.img.img_ptr, col, row);
			else if (mlx->map[row][col] == 'C')
				ft_put_img_win(mlx, mlx->collect.img.img_ptr, col, row);
			col++;
		}
		row++;
	}
}

static void	draw_row(t_mlx *mlx, char *line, int row)
{
	int		i;

	i = 0;
	mlx->map[row] = (char *)malloc(sizeof(char) * mlx->map_width);
	while (line[i])
	{
		if (line[i] == 'P')
		{
			if (mlx->player.x)
				handle_error(DUP_P);
			mlx->player.x = i;
			mlx->player.y = row;
		}
		else if (line[i] == 'C')
			mlx->collect.cnt++;
		else if (line[i] == 'E')
		{
			mlx->exit.y = i;
			mlx->exit.x = row;
		}
		mlx->map[row][i] = line[i];
		i++;
	}
}

void	map_parse(t_mlx *mlx, int fd)
{
	char	*line;
	int		row;

	row = 0;
	mlx->map = (char **)malloc(sizeof(char *) * mlx->map_height);
	if (!mlx->map)
		error();
	mlx->collect.cnt = 0;
	line = gnl(fd, mlx->map_width);
	while (line)
	{
		draw_row(mlx, line, row);
		free(line);
		line = gnl(fd, mlx->map_width);
		row++;
	}
	free(line);
	if (mlx->player.x == 0)
		handle_error(NOT_P);
	if (mlx->exit.x == 0)
		handle_error(NOT_E);
}
