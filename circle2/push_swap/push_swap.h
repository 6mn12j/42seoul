/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/25 02:18:50 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_listNodeType
{
	int						data;
	struct s_listNodeType	*p_left;
	struct s_listNodeType	*p_right;
}			t_listnode;

typedef struct s_listType
{
	int			current_element_count;
	t_listnode	header_node;
}			t_list;

typedef struct s_allType
{
	t_list	*list_a;
	t_list	*list_b;
	int		*arr;
}			t_all;

void		r_ab(t_list *t_list);
void		rr(t_list *a_list, t_list *b_list);
void		rr_ab(t_list *t_list);
void		rrr(t_list *a_list, t_list *b_list);
void		s_ab(t_list *t_list);
void		ss(t_list *a_list, t_list *b_list);
void		p_ab(t_list *start_list, t_list *target_list);
void		displayt_list(t_list *pList);
int			get_list_length(t_list *pList);
int			add_element(t_list *p_list, int position, t_listnode element);
int			remove_element(t_list *pList, int position);
void		deletet_list(t_list *pList);
void		cleart_list(t_list *pList);
t_list		*create_list(void);
t_listnode	*get_element(t_list *pList, int position);
void		display(t_list *pList);
int			set_list_a(char *argv, t_list *p_list);
void handle_argument(char *argv,t_list *list_a);
int			main(int argc, char *argv[]);
void error();

int	is_space(char c);
size_t		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
#endif
