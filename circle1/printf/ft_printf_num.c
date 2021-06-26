/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:16:44 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/26 20:24:40 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_maxlength(t_flag *f, int value)
{
	// printf("pre:%d\n",f->precision);
	// printf("pre_v:%d\n",f->precision_value);
	int result;
	int	is_minus;

	is_minus = 0;
	if (value < 0)
	{
		is_minus = 1;
		value *= -1;
	}
	if (f->precision && f->precision_value > digitlen(value))
		result = f->precision_value + is_minus;
	else if (f->zero == 1 && !f->precision && !f->minus)
		result = f->width >= digitlen(value) + is_minus ?
f->width : digitlen(value) + is_minus;
	else
		result = digitlen(value) + is_minus;

	return (result);
}

void	make_width(char **backup, t_flag *f, int width_len)
{
	char *width_space;
	char *tmp;
	int i;

	i = 0;
	tmp = *backup;
	width_space = (char *)malloc(sizeof(char) * (width_len + 1));
	width_space[width_len] = '\0';

	while (i < width_len)
		width_space[i++] = ' ';

	if (f->minus)
		*backup = ft_strjoin(*backup, width_space);
	else
		*backup = ft_strjoin(width_space, *backup);
	free(tmp);
	tmp = 0;
	free(width_space);
	width_space = 0;
	return ;
}


int		ft_printf_d(t_flag *f, va_list ap)
{
	int v;
	int length;
	int width_len;
	char *backup;

	v = va_arg(ap, int);
	length = find_maxlength(f, v);
	if (f->precision && f->precision_value == 0 && v == 0)
		length = 0;
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (-1);
	backup[length] = '\0';
	if (f->precision || f->zero)
		ft_memset(backup, '0', length);
	int i;
	if (v < 0)
	{
		backup[0] = '-';
		v = v * -1;
	}
	i = length;
	while (v)
	{
		backup[--i] = (v % 10 + '0');
		v = v / 10;
	}
	width_len = f->width - length;
	if (width_len > 0)
		make_width(&backup, f, width_len);

	while (*backup)
	{
		f->return_value += write(1, backup, 1);
		backup++;
	}
	return (1);
}