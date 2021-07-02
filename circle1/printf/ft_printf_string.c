/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:54:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/02 16:15:14 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_strmaxlength(t_flag *f,int	str_len)
{
	int	result;

	result = 0;
	if (f->spec != 'c' && f->precision && f->precision_value < str_len)
		result = f->precision_value;
	else if (f->spec != 'c' && f->precision && f->precision_value > str_len)
		result = str_len;
	else if (f->spec != 'c' && f->precision && f->precision_value == 0)
		result = 0;
	else
		result = str_len;
	return (result);
}

int		ft_printf_string(t_flag *f, char *v)
{
	char *backup;
	int	str_len;
	int	length;
	if (v == NULL)
		v = "(null)";
	str_len = ft_strlen(v);
	length = find_strmaxlength(f, str_len);
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	backup[length] = '\0';
	f->spec == 'c' ? backup[0] = v[0] : ft_strlcpy(backup, v, length + 1);
	if (f->width - length > 0)
		make_width(&backup, f, f->width - length);
	f->return_value += write(1, backup, ft_strlen(backup));
	return (1);
}

int		ft_printf_string_c(t_flag *f, char v)
{
	char fill_space;
	fill_space = ' ';
	if (f->spec == '%' && f->minus ==0)
		fill_space = f->zero == -1 ? ' ' : '0';
	if (f->width > 1)
	{
		if (f->minus)
		{
			f->return_value +=write(1, &v, 1);
			while(--f->width)
				f->return_value +=write(1, &fill_space, 1);
			return (1);
		}
		else
		{
			while(--f->width)
				f->return_value +=write(1, &fill_space, 1);
			f->return_value +=write(1, &v, 1);
			return (1);
		}
	}
	f->return_value +=write(1, &v, 1);
	return (1);
}