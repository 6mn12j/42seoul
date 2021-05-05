/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:29:10 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/04 15:46:12 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	unsigned char target;

	target = c;
	if (target >= 'A' && target <= 'Z')
		return (target + 32);
	else
		return (target);
}
