/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/24 05:26:16 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "./get_next_line.h"

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자
# define KEY_W 13 //'W'
# define KEY_A 0 //'A'
# define KEY_S 1 //'S'
# define KEY_D 2//'D'
# define KEY_ESC 53 //'ESC'
# define RED_BUTTON 17 //'종료 버튼'
# define TILE 60

//플레이어(가만히, 뛰는거)  벽 길 먹는거 탈출구
typedef struct img
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			*data;
}t_img;

typedef struct s_player
{
	int				x;
	int				y;
	char			prev;
	int				step;
	t_img			img;
}	t_player;

typedef struct s_collection
{
	int				cnt;
	t_img			img;

}	t_collection;

typedef struct s_wall
{
	t_img			img;
}	t_wall;

typedef struct s_tile
{
	t_img			img;
}	t_tile;

typedef struct s_exit
{
	int				is_touch;
	t_img			img;

}	t_exit;

typedef struct s_img_size
{
	int 			width;
	int				height;
}t_img_size;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				map_width;
	int				map_height;
	t_img			img;
	t_img_size		img_size;
	t_tile			tile;
	t_exit			exit;
	t_wall			wall;
	t_player		player;
	t_collection	collections;
}	t_mlx;

int		valid_map(t_mlx *mlx);
void	fill_map(t_mlx *mlx, int fd);
int		get_map_width_col_valid(int fd, t_mlx *mlx);
void	handle_draw(t_mlx *mlx);
void	handle_init(t_mlx *mlx);
void	error(void);
void	not_square(void);



#endif