/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:30:54 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/04 15:09:54 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

static	int		ft_isalpha(int c)
{
	unsigned char target;

	target = c;
	if ((target >= 'a' && target <= 'z') || (target >= 'A' && target <= 'Z'))
		return (1);
	else
		return (0);
}

int				ft_isalnum(int c)
{
	unsigned char target;

	target = c;
	if (ft_isalpha(target) || ft_isdigit(target))
		return (1);
	else
		return (0);
}
