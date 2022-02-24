/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/24 19:56:33 by minjupar         ###   ########.fr       */
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

static int	is_space(char c)
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

int	simple_atoi(const char *str)
{
	int			i;
	int			sign;
	char		*temp;
	long long	result;

	temp = (char *)str;
	result = 0;
	i = 0;
	sign = 1;
	while (is_space(temp[i]))
		i++;
	if (temp[i] == '-' || temp[i] == '+')
		sign = temp[i++] == '-' ? -1 : 1;
	if (temp[i] == '-' || temp[i] == '+' || !ft_isdigit(temp[i]))
	{
		printf("error\n");
		exit(0);
	}
	while (ft_isdigit(temp[i]))
	{
		result = (result * 10) + (temp[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}

int	valid_input(char *argv, t_list *p_list)
{
	t_listnode	temp;

	temp.data = simple_atoi(argv);
	if (temp.data)
		add_element(p_list, 0, temp);
	else
		return (-1);
	return (1);
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
				printf("display3\n");

			pPreNode = pPreNode->p_right ;
			printf("%d ", pPreNode->data);
		}
		printf("\n");
}

