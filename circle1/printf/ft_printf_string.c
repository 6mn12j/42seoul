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

	result = 0;
	if (f->precision && f->precision_value < str_len)
		result = f->precision_value;
	else if (f->precision && f->precision_value > str_len)
		result = str_len;
	else if (f->precision && f->precision_value == 0)
		result = 0;
	else
		result = str_len;
	return (result);
}

int		ft_printf_string(t_flag *f, va_list *ap, char spec)
{
	char *v;
	char *backup;
	int	str_len;
	int	length;
	f->spec = spec;
	v = va_arg(*ap, char *);
	if (v == NULL)
		v = "(null)";
	if (f->spec == 'c')

	str_len = ft_strlen(v);
	length = find_strmaxlength(f, str_len);
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	backup[length] = '\0';
	ft_strlcpy(backup, v, length + 1);
	if (f->width - length > 0)
		make_width(&backup, f, f->width-length);
	while (*backup)
	{
		f->return_value += write(1, backup, 1);
		backup++;
	}
	return (1);
}