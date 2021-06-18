/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:47:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/18 22:13:30 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	init_flag(struct ft_flag *f)
{
	f->star = 0;
	f->zero = -1;
	f->minus = -1;
	f->width = 0;
	f->precision = -1;
	f->return_value = 0;
}

int		is_spec(const char *format)
{
	if (*format == 'c' || *format == 's' ||
		*format == 's' || *format == 'd' ||
		*format == 'i' || *format == 'u' ||
		*format == 'x' || *format == 'X')
		return (1);
	return (-1);
}

int		handle_flag(const char *format, struct ft_flag *f, va_list ap)
{
	while (is_spec(format) != 1)
	{
		if (*format == '-')
			f->minus = 1;
		else if (*format == '0' && f->precision == -1)
			f->zero = 1;
		else if (*format == '.')
		{

			f->precision = 0;
			//printf("in precision %c\n", *format);
			format++;
			if (f->precision == '-')
			{
				f->precision = -1;
				while (ft_isdigit(*format))
					format++;
				continue ;
			}
			//printf("in precision2 %c\n", *format);
			if (*format == '*')
				f->star = va_arg(ap, int);
			while (ft_isdigit(*format))
			{
				f->precision = (f->precision) * 10 + (*format - '0');
				format++;
			}
			//printf("precision : %d\n",f->precision);
			if (f->star)
			{
				f->precision = f->star;
				f->star = 0;
			}
			continue ;
		}
		else if (*format == '*')
		{
			format++;
			f->width = va_arg(ap, int);
			printf("가변인자 전 스타%d\n",f->star);
			printf("가변인자 와이드 %d\n",f->width);
		}
		else if (ft_isdigit(*format))
		{
			while (ft_isdigit(*format))
			{
				f->width = (f->width) * 10 + (*format - '0');
				format++;
			}
			continue;
		}
		if (f->star)
			f->width = f->star;
		format++;
	}
	if (is_spec(format))
		return (1);
	return (-1);
}

void	ft_printf_d(const char *format, struct ft_flag *f)
{

	printf("* : %d\n", f->star);
	printf("0 : %d\n", f->zero);
	printf("- : %d\n", f->minus);
	printf("width : %d\n", f->width);
	printf(". : %d\n", f->precision);
	printf("return value : %d\n", f->return_value);
}


int		ft_printf(const char *format, ...)
{
	int length;
	va_list ap;

	va_start(ap, format);
	struct ft_flag f;
	init_flag(&f);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			f.return_value += 1;
			continue ;
		}
		else if (*format == '%')
		{
			format++;
			if (handle_flag(format, &f, ap) == 1)
				ft_printf_d(format, &f);
			else
				return (-1);
		}
	}

	return (f.return_value);
}

int		main()
{
	//int return1 = printf("|%04.d|\n",3);
	//int return2 = ft_printf("|%04.d|\n",3);
	int return3 = printf("|%-010.4d|\n",3);
	int return4 = ft_printf("|%010.4d|\n",3);
	printf("---프리시전에 * 카드로 음수가 들어올때 ---\n");
	int return5 = printf("|%010.*d|\n",-3, 3);
	int return6 = ft_printf("|%010.*d|\n",-3, 3);
	printf("\n-----프리시전에 그냥 음수 들어올 때-----\n");
	int return7 = printf("|%010.-3d|\n",3);
	int return8 = ft_printf("|%010.-3d|\n",3);
	printf("--------------------------\n");
	//printf("return 1: %d\n", return1);
	//printf("return 2: %d\n", return2);
	printf("return 3: %d\n", return3);
	printf("return 4: %d\n", return4);
}