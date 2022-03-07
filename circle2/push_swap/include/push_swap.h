/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/07 01:43:28 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_commandNodeType
{
	char						*data;
	struct s_commandNodeType	*p_left;
	struct s_commandNodeType	*p_right;
}			t_command;

typedef struct s_commandType
{
	int			current_node_count;
	t_command	header_node;
}			t_commandlist;

typedef struct s_listNodeType
{
	int						data;
	struct s_listNodeType	*p_left;
	struct s_listNodeType	*p_right;
}			t_listnode;

typedef struct s_listType
{
	int			current_node_count;
	t_listnode	header_node;
}			t_list;

typedef struct s_allType
{
	t_list			*list_a;
	t_list			*list_b;
	t_commandlist	*list_command;
	int *arr;
}			t_all;

//command
void		r_ab(t_all *all_list, t_list *t_list, char target);
void		rr(t_all *all_list, t_list *a_list, t_list *b_list, char target);
void		rr_ab(t_all *all_list, t_list *t_list, char target);
void		rrr(t_all *all_list, t_list *a_list, t_list *b_list, char target);
void		s_ab(t_all *all_list, t_list *t_list, char target);
void		ss(t_all *all_list, t_list *a_list, t_list *b_list, char target);
void		p_ab(t_all *all_list, t_list *start_list, t_list *target_list, char target);

//doublylist
void			display_listt_list(t_list *pList);
int				get_list_length(t_list *pList);
int				add_element(t_list *p_list, int position, t_listnode element);
int				add_command(t_commandlist *p_list, int position, char *element);
int				remove_element(t_list *pList, int position);
void			deletet_list(t_list *pList);
void			cleart_list(t_list *pList);
void			display_list(t_list *pList);
t_list			*create_list(void);
t_commandlist	*create_command_list(void);
t_listnode		*make_list_node(int data);
t_listnode		*get_node(t_list *pList, int position);

//utils
int			is_ascending(t_list *list, int start_index, int end_index);
int			is_descending(t_list *list, int start_index, int end_index);
int			is_space(char c);
int			is_digit(int num);
int			ft_atoi(const char *str, t_all *all_list);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);


//push_swap
void	handle_swap(t_all *all, char target);
void	tA_to_B(t_all *all, int start_index, int end_index);
void	bA_to_B(t_all *all, int start_index, int end_index);
void	tB_to_A(t_all *all, int start_index, int end_index);
void	bB_to_A(t_all *all, int start_index, int end_index);

int			main(int argc, char *argv[]);
void 		error(void);
void 		handle_argument(char *argv, t_all *all_list);
int	find_pivot(int start_index, int end_index, int type);

void	handle_three_tb(t_all *all, int start_index, int end_index);
void	handle_three_ta(t_all *all, int start_index, int end_index);
#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_

#define SMALL		1
#define BIG			2

#endif
