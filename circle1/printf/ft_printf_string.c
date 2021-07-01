/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:54:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/01 20:42:17 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_strmaxlength(t_flag *f,int	str_len)
{
	int	result;

	if (f->precision && f->precision_value < str_len)
		result = f->precision_value;
	else if (f->precision && f->precision_value > str_len)
		result = str_len;
	else if (f->precision && f->precision_value == 0)
		result = 0;
	return (result);
}

int		ft_printf_string(t_flag *f, va_list *ap, char spec)
{
	char *v;
	char *backup;
	int	str_len;

	v = va_arg(*ap, char *);
	str_len = ft_strlen(v);
	length = find_strmaxlength(f, str_len);
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	return (1);
}