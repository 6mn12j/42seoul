/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/12 21:37:15 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_argument(char *argv, t_all *all)
{
	char	*test;

	test = ft_strtrim(argv, " ");
	if(!*test)
		error();
	ft_atoi(test, all);
}

static	void	handle_add(t_all *all, long long data)
{
	int	current_count;

	current_count = all->list_a->current_node_count;
	if ((data < -2147483648) || (data > 2147483647))
		error();
	add_element(all->list_a, current_count, *make_list_node(data));
}

static int	find_sign(const char data)
{
	if (data == '-')
		return (-1);
	else if (data == '+')
		return (1);
	return (1);
}

int	ft_atoi(const char *str, t_all *all)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	while (str[i])
	{
		sign = 1;
		result = 0;
		while (is_space(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
			sign = find_sign(str[i++]);
		if (!is_digit(str[i]))
			error();
		while (is_digit(str[i]))
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		handle_add(all, (long long)(sign * result));
		if (str[i] && !is_space(str[i]))
			error();
	}
	return (1);
}

int	find_pivot(int start_index, int end_index, int type)
{
	int	small_index;
	int	big_index;

	if (end_index - start_index == 0)
		return (start_index);
	if (end_index - start_index < 2)
		return (start_index + 1);
	small_index = start_index + ((end_index - start_index) + 1) / 3;
	big_index = ((end_index - small_index) / 2) + small_index ;
	if (type == SMALL)
		return (small_index);
	else if (type == BIG)
		return (big_index);
	return (0);
}
