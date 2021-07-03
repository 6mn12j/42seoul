/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:47:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/02 21:48:56 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int m_cnt;
int f_cnt;

void	init_flag(t_flag *f)
{
	f->zero = -1;
	f->minus = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_value = 0;
	f->spec = 0;
	f->is_minus = 0;
}

int		get_flag_num(const char **format, va_list *ap)
{
	int num;

	num = 0;
	if (**format == '*')
	{
		num = va_arg(*ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			num = num * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (num);
}

int		handle_flag(const char **format, t_flag *f, va_list *ap)
{
	if (**format == ' ')
		(*format)++;
	while (**format == '-' || **format == '0')
	{
		if (**format == ' ')
			(*format)++;
		if (**format == '-')
			f->minus = 1;
		else if (**format == '0')
			f->zero = 1;
		(*format)++;
	}
	f->width = get_flag_num(format, ap);
	if (f->width < 0)
	{
		f->width *= -1;
		f->minus = 1;
	}
	if (**format == '.')
	{
		f->precision = 1;
		(*format)++;
		if (**format == '-')
		{
			f->precision = 0;
			(*format)++;
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			f->precision_value = get_flag_num(format, ap);
	}
	if (is_spec(**format))
	{
		f->spec = **format;
		return (1);
	}
	return (-1);
}

void	clear_flag(t_flag *f)
{
	if (f->spec == '%')
		f->precision = 0;
	if (f->precision_value < 0)
		f->precision = 0;
	if (f->minus && f->zero && f->spec != '%')
		f->zero = -1;
	if (f->precision == 1 && f->zero)
		f->zero = -1;
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_flag f;

	va_start(ap, format);
	f.return_value = 0;
	m_cnt = 0;
	f_cnt = 0;
	while (*format)
	{
		init_flag(&f);
		if (*format != '%')
		{
			f.return_value += write(1, format, 1);
			format++;
			continue ;
		}
		else if (*format == '%')
		{
			format++;
			f.spec = *format;
			if (handle_flag(&format, &f, &ap) == 1)
			{
				f.spec = *format;
				clear_flag(&f);
				if (f.spec == 'd' || f.spec == 'i' || f.spec == 'u' ||
				f.spec == 'x' || f.spec == 'X' || f.spec =='p')
					ft_printf_num(&f, &ap);
				else if (f.spec == 'p')
					ft_printf_num(&f, &ap);
				else if (f.spec == 's')
					ft_printf_string(&f, va_arg(ap, char *));
				else if (f.spec == 'c')
					ft_printf_string_c(&f, va_arg(ap, int));
				else if (f.spec == '%')
					ft_printf_string_c(&f, f.spec);
				++format;
			}
		}
		if (!f.spec)
			return (0);
	}
	//printf("mallodc:%d free:%d\n",m_cnt, f_cnt);
	va_end(ap);
	return (f.return_value);
}
