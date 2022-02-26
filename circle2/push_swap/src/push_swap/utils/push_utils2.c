/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/27 05:19:02 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void handle_argument(char *argv, t_all *all_list)
{
	char *test;

	test = ft_strtrim(argv, " ");
	ft_atoi(test, all_list);
}

static void handle_add(t_all * all_list, int data)
{
	int current_count;

	current_count = all_list->list_a->current_element_count;
	if ((data < -2147483648)|| (data > 2147483647))
			error();
	add_element(all_list->list_a, current_count, *make_list_node(data));
}

static int	find_sign(const char data)
{
	if (data == '-')
		return (-1);
	else if (data == '+')
		return (1);
	return (1);
}

int	ft_atoi(const char *str, t_all *all_list)
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
		handle_add(all_list, (int)(sign * result));
		if(str[i] && !is_space(str[i]))
			error();
	}
	return (1);
}

