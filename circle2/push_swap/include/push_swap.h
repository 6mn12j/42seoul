/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 17:06:27 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

# define SMALL		1
# define BIG		2

typedef struct s_command_node_type
{
	char						*data;
	struct s_command_node_type	*p_left;
	struct s_command_node_type	*p_right;
}				t_command;

typedef struct s_command_type
{
	int			current_node_count;
	t_command	header_node;
}			t_commandlist;

typedef struct s_list_node_type
{
	int						data;
	struct s_list_node_type	*p_left;
	struct s_list_node_type	*p_right;
}			t_listnode;

typedef struct s_list_type
{
	int			current_node_count;
	t_listnode	header_node;
}			t_list;

typedef struct s_all_type
{
	t_list			*list_a;
	t_list			*list_b;
	t_commandlist	*list_command;
	int				*arr;
}			t_all;
void			s_ab(t_all *all, t_list *t_list, char target);
void			r_ab(t_all *all, t_list *t_list, char target);
void			rr_ab(t_all *all, t_list *t_list, char target);
void			ss(t_all *all, t_list *a_list, t_list *b_list, char target);
void			rr(t_all *all, t_list *a_list, t_list *b_list, char target);
void			rrr(t_all *all, t_list *a_list, t_list *b_list, char target);
void			p_ab(t_all *all, t_list *start_list,
					t_list *target_list, char target);
int				add_element(t_list *p_list, int position, t_listnode element);
int				add_command(t_commandlist *p_list, int position, char *element);
int				remove_element(t_list *pList, int position);
int				remove_command(t_commandlist *pList, int position);
void			deletet_list(t_list *pList);
void			clear_list(t_list *pList);
void			display(t_list *pList);
void			display_command(t_commandlist *pList);
t_list			*create_list(void);
t_commandlist	*create_command_list(void);
t_listnode		*make_list_node(int data);
t_listnode		*get_node(t_list *pList, int position);
int				is_ascending(t_list *list, int start_index, int end_index);
int				is_descending(t_list *list, int start_index, int end_index);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				is_space(char c);
int				is_digit(int num);
void			ft_putstr_fd(char *str, int fd);
int				ft_atoi(const char *str, t_all *all);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
void			top_a_sort(t_all *all, int start_index, int end_index);
void			top_b_sort(t_all *all, int start_index, int end_index);
void			bottom_a_sort(t_all *all, int start_index, int end_index);
void			bottom_b_sort(t_all *all, int start_index, int end_index);
void			b_top_recur(t_all *all, int start_index, int end_index);
void			a_top_recur(t_all *all, int start_index, int end_index);
void			b_bottom_recur(t_all *all, int start_index, int end_index);
void			a_bottom_recur(t_all *all, int start_index, int end_index);
int				find_pivot(int start_index, int end_index, int type);
void			handle_argument(char *argv, t_all *all);
void			error(void);
int				main(int argc, char *argv[]);
void			handle_swap(t_all *all, char target);
void			handle_three_tb(t_all *all, int start_index, int end_index);
void			handle_three_ta(t_all *all, int start_index, int end_index);
void			handle_only_3_tb(t_all *all, int start_index, int end_index);
void			handle_only_3_ta(t_all *all, int start_index, int end_index);
void			handle_five(t_all *all);
void			command_optimization(t_commandlist *list);

#endif