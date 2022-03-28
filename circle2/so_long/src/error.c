/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/28 00:58:00 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	handle_error(int flag)
{
	printf("Error\n");
	if (flag == NOT_SQUARE)
		printf("not square \n");
	else if (flag == NOT_WALL)
		printf("not valid map (wall)\n");
	else if (flag == NOT_VALID)
		printf("not valid map (valid only 1,0,P,C,E)\n");
	exit(EXIT_FAILURE);
}

void	handle_valid(t_mlx *mlx)
{
	if (mlx->player.cnt != 1)
		valid_check(mlx);
	if (mlx->collect.cnt <= 0)
		valid_check(mlx);
	if (mlx->exit.cnt <= 0)
		valid_check(mlx);
}

void	valid_check(t_mlx *mlx)
{
	printf("Error\n");
	if (mlx->player.cnt == 0)
		printf("no player\n");
	if (mlx->player.cnt > 1)
		printf("duplicate player\n");
	if (mlx->collect.cnt == 0)
		printf("no collect\n");
	if (mlx->exit.cnt == 0)
		printf("no exit\n");
	exit(EXIT_SUCCESS);
}
