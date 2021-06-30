/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:16:44 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/29 21:31:13 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_maxlength(t_flag *f, long long value)
{
	// printf("pre:%d\n",f->precision);
	// printf("pre_v:%d\n",f->precision_value);
	int result;
	int is_minus;

	is_minus = 0;
	//printf("maxlength_value:%lld\n",value);
	//printf("widht:%d\n",f->width);
	if (value < 0)
	{
		is_minus = 1;
		value *= -1;
	}
	if (f->precision && f->precision_value + is_minus > value + is_minus)
		result = f->precision_value + is_minus;
	else if (f->zero == 1 && !f->precision && !f->minus)
		result = f->width >= value + is_minus ?
f->width : value + is_minus;
	else
		result = value + is_minus;
	//printf("result:%lld\n",result);
	//printf("ft_digitlen:%d\n",ft_digitlen(value));
	return (result);
}

int		my_free(char *str)
{
	free(str);
	str = 0;
	return (1);
}

int		make_width(char **backup, t_flag *f, int width_len)
{
	char *width_space;
	char *tmp;
	long long i;

	i = 0;
	tmp = *backup;
	width_space = (char *)malloc(sizeof(char) * (width_len + 1));
	if (!width_space)
		return (0);
	width_space[width_len] = '\0';
	while (i < width_len)
		width_space[i++] = ' ';
	if (f->minus)
		*backup = ft_strjoin(*backup, width_space);
	else
		*backup = ft_strjoin(width_space, *backup);
	if (!backup)
		return (0);
	my_free(tmp);
	my_free(width_space);

	return (1);
}

int		ft_printf_num(t_flag *f, va_list *ap, char spec)
{
	long long v;
	char* temp;
	long long length;
	long long width_len;
	char *backup;

	v = 0;
	if (spec == 'd' || spec == 'i')
		v = va_arg(*ap, int);
	else if (spec == 'u')
		v = va_arg(*ap, unsigned int);
	else if (spec == 'x' || spec == 'X')
	{
		v = va_arg(*ap, unsigned int);
		//printf("\nvalue1:%lld\n",temp);
		temp = ft_putnbr_base(v, "0123456789abcdef");
		printf("\n temp:%s\n", temp);
		//printf("\nvalue2:%lld",temp);
	}
	v = spec == 'x' || spec == 'X' ? ft_strlen(temp) : ft_digitlen(v);
	length = find_maxlength(f, v);
	if (f->precision && f->precision_value == 0 && v == 0)
		length = 0;
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
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
