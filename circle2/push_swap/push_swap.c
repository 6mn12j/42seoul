/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/25 02:35:29 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\f'
		|| c == '\r'
		|| c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

static int	find_sign(const char data)
{
	if (data == '-')
		return (-1);
	else if (data == '+')
		return (1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = find_sign(str[i++]);
	if (!ft_isdigit(str[i]))
		error();
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if ((sign == -1 && result > 2147483648)
		|| (sign == 1 && result > 2147483647))
		error();
	return ((int)(sign * result));
}

int	set_list_a(char *str, t_list *p_list)
{
	t_listnode	temp;

	temp.data = ft_atoi(str);
	if (temp.data)
		add_element(p_list, p_list->current_element_count, temp);
	else
		error();
	return (1);
}

void handle_argument(char *argv, t_list *list_a)
{
	char *test;
	int j = 0;

	test = ft_strtrim(argv, " ");
	if (test)
	{
		while (test[j])
		{
			test = ft_strtrim(test," ");
			while (is_space(test[j]))
				j++;
			set_list_a(&test[j++],list_a);
		}
	}
	else
		set_list_a(argv,list_a);
}

void	display(t_list *pList)
{
	if (pList -> current_element_count == 0 )
	{
		printf("빈배열\n");
		return ;
	}
		t_listnode *pPreNode;

		pPreNode = &(pList->header_node);

		for (int i = 0 ; i < pList->current_element_count; i++)
		{
			pPreNode = pPreNode->p_right ;
			printf("%d ", pPreNode->data);
		}
		printf("\n");
}
