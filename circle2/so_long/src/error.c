/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 22:39:37 by minjupar         ###   ########.fr       */
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
	else if (flag == NOT_P)
		printf("no player\n");
	else if (flag == DUP_P)
		printf("duplicate player\n");
	else if (flag == NOT_C)
		printf("no collect\n");
	else if (flag == NOT_E)
		printf("no exit\n");
	else if (flag == NOT_WALL)
		printf("ot valid map\n");
	else if (flag == NOT_ARGUMENT)
		printf("Argument Error\n");
	exit(EXIT_FAILURE);
}
