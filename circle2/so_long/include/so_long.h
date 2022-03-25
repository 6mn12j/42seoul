/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/25 23:50:51 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "./get_next_line.h"

# define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자
# define KEY_W 13 //'W'
# define KEY_A 0 //'A'
# define KEY_S 1 //'S'
# define KEY_D 2//'D'
# define KEY_ESC 53 //'ESC'
# define ON_DESTROY 17 //'종료 버튼'
# define TILE 60

# define NOT_SQUARE 1
# define NOT_VALID 2
# define NOT_WALL 3

typedef struct s_img
{
	void		*img_ptr;
	int			bpp;
	int			size_l;
	int			endian;
	int			*data;
}	t_img;

typedef struct s_player
{
	int				x;
	int				y;
	int				cnt;
	char			prev;
	int				step;
	t_img			img;
}	t_player;

typedef struct s_collect
{
	int				cnt;
	t_img			img;

}	t_collect;

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
	int				y;
	int				x;
	int				cnt;
	t_img			img;

}	t_exit;

typedef struct s_img_size
{
	int				width;
	int				height;
}t_img_size;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				map_width;
	int				map_height;
	int				fd;
	t_img			img;
	t_img_size		img_size;
	t_tile			tile;
	t_exit			exit;
	t_wall			wall;
	t_player		player;
	t_collect		collect;
}	t_mlx;

int		close_game(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		valid_map(t_mlx *mlx);
void	fill_map(t_mlx *mlx);
void	re_fillmap(t_mlx *mlx);
void	map_parse(t_mlx *mlx, int fd);
void	open_map_file(t_mlx *mlx, char*file);
void	error(void);
void	valid_check(t_mlx *mlx);
void	handle_valid(t_mlx *mlx);
void	handle_error(int flag);
void	init(t_mlx *mlx);
void	mlx_win_init(t_mlx *mlx);
void	img_init(t_mlx *mlx);
#endif
