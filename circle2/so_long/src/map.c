/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 05:40:22 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


static int	valid_value(char c)
{
	if (c == '1' || c == '0' || c =='C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

int		valid_map(t_mlx *mlx)
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
					error();
			}
			if (!valid_value(mlx->map[i][j]))
				error();
			j++;
		}
		i++;
	}
	return (1);
}

int		get_map_width_col_valid(int fd, t_mlx *mlx)
{
	int		map_col;
	char	buf;

	map_col = 0;
	//TODO init으로 분리
	mlx->map_width = 0;
	mlx->map_height = 0;
	while (read(fd, &buf, 1) == 1)
	{
		map_col++;
		if (buf == '\n')
		{
			printf("%d %d\n",mlx->map_width, map_col-1);
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
				error();
			mlx->player.x = i;
			mlx->player.y = row;
		}
		else if (line[i] == 'C')
			mlx->collections.cnt++;

		mlx->map[row][i] = line[i];
		i++;
	}
}

void	fill_map(t_mlx *mlx, int fd)
{
	char	*line;
	int		row;

	row = 0;
	mlx->map = (char **)malloc(sizeof(char *) * mlx->map_height);
	if (!mlx->map)
		error();
	mlx->collections.cnt = 0;

	line = gnl(fd, mlx->map_width);
	while (line)
	{
		draw_row(mlx, line, row);
		free(line);
		line = gnl(fd, mlx->map_width);
		row++;
	}
	if (mlx->player.x  == 0)
		error();
}

