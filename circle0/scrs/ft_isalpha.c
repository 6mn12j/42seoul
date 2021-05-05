/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:18:57 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/04 15:02:54 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	unsigned char target;

	target = c;
	if ((target >= 'a' && target <= 'z') || (target >= 'A' && target <= 'Z'))
		return (1);
	else
		return (0);
}
