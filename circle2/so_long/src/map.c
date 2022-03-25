/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/25 17:35:56 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	valid_value(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

int	valid_map(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mlx->map_height)
	{
		j = 0;
		while (j < mlx->map_width)
		{
			if (i == 0 || i == mlx->map_height - 1 || \
				j == 0 || j == mlx->map_width - 1)
			{
				if (mlx-> map[i][j] != '1')
					handle_error(NOT_WALL);
			}
			if (!valid_value(mlx->map[i][j]))
				handle_error(NOT_WALL);
			j++;
		}
		i++;
	}
	return (1);
}

static int	get_map_size(int fd, t_mlx *mlx)
{
	int		map_col;
	char	buf;

	map_col = 0;
	while (read(fd, &buf, 1) == 1)
	{
		map_col++;
		if (buf == '\n')
		{
			if (mlx->map_width != 0 && mlx->map_width != map_col - 1)
				return (0);
			mlx->map_height ++;
			mlx->map_width = --map_col;
			map_col = 0;
		}
	}
	close(fd);
	return (1);
}

void	re_fillmap(t_mlx *mlx)
{
	t_player	player;

	player = mlx->player;
	mlx->map[player.y][player.x] = 'P';
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	fill_map(mlx);
}

void	open_map_file(t_mlx *mlx, char*file)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error();
	if (!get_map_size(fd, mlx))
		handle_error(NOT_SQUARE);
	fd = open(file, O_RDONLY);
	map_parse(mlx, fd);
	if (!valid_map(mlx))
		error();
	return ;
}
