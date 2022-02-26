/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:08:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/02/27 05:06:00 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_digit(int num)
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
