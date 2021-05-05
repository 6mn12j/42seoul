/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:22:46 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/04 15:46:23 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	unsigned char target;

	target = c;
	if (target >= 'a' && target <= 'z')
		return (target - 32);
	else
		return (target);
}
