/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:47:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/26 20:28:55 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flag *f)
{
	f->zero = -1;
	f->minus = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_value = 0;
	f->spec = 0;
}

int		get_flag_num(const char **format, va_list ap)
{
	int num;

	num = 0;
	if (**format == '*')
	{
		num = va_arg(ap, int);
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

int		handle_flag(const char **format, t_flag *f, va_list ap)
{


	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			f->minus = 1;
		else if (**format == '0')
			f->zero = 1;
		(*format)++;
	}
	f->width = (get_flag_num(format, ap));
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
		{
			f->precision_value = (get_flag_num(format, ap));
		}
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
	if (f->precision_value < 0)
		f->precision = 0;
	if (f->minus && f->zero)
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
			if (handle_flag(&format, &f, ap) == 1)
			{

				clear_flag(&f);
				if (*format == 'd')
				 	ft_printf_d(&f, ap);
				// else if (*format == 'i')
				//  	ft_printf_i(&format, &f, ap);
				// else if (*format == 's')
				// 	ft_printf_s(&format, &f, ap);
				// else if (*format == 'c')
				// 	ft_printf_c(&foramt ,&f, ap);
				// else if (*format == 'u')
				// 	ft_printf_u(&format, &f, ap);
				// else if (*format == 'x')
				// 	ft_printf_x(&format, &f, ap);
				// else if (*foramt == 'X')
				// 	ft_printf_X(&format &f,ap);
				format++;
			}
			else
				return (-1);
		}
	}
	return (f.return_value);
}
