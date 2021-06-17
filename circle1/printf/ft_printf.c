/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:54:29 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/16 22:08:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"


void	init_flag(struct *f)
{
	f->star = 0;
	f->zero = 0;
	f->flag = -1;
	f->minus = -1;
	f->width = 0;
	f->precision = -1;
	f->return_value = 0;
}

int		is_cspdiuxX(char *format)
{
	if (*foramat == 'c' || *foramat == 's' ||
		*foramat == 's' || *foramat == 'd' ||
		*foramat == 'i' || *foramat == 'u' ||
		*foramat == 'x' || *foramat == 'X' ||)
		return (1);
	return(-1);
}

int	handle_plag(char *foramt, struct ft_flag *f, va_list ap)
{
	while(is_cspdiuxX(*format) != 1)
	{
		if (*format == '.')
			f->precision = 0;
		else if (*format == '-')
			f->munus = 1;
		else if (*format == '0')
			f->zero = 1;
		else if (*format == '*')
		{
			*foramt ++
			f->star = va_arg(ap, int);
		}
		else if (is_digit(*format) && f->precision == -1)
			f->width += *format * 10;
		else if (is_digist(*foramt) && f->precision != -1)
			f->precision += *format * 10;
		*format++;
	}
	if(is_cspdiuxX(*format))
		return (1);
	return (-1);
}

void check_type(char *format, struct ft_flag *f)
{
	if (*format == 'c')
		ft_printf_c(*format, f)
	else if (*format == 's')
		ft_printf_s(*format, f)
	else if (*format == 'd' || *format == 'i')
		ft_printf_d(*format, f)
	else if (*format == 'u')
		ft_printf_u(*format, f)
	else if (*format == 'x')
		ft_printf_x(*format, f)
	else if (*format == 'X')
		ft_printf_X(*format, f)

}


int ft_printf(const char *format, ...)
{
	int length;
	va_list ap;

	va_start(ap, *format);
	struct ft_plag *f = malloc(sizeof(struct ft_plag));
	init_plag(*f);
	return_value = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			*format++;
			f->return_value =+ 1;
			break;
		}
		if (*format++ == '%')
		{
			if (handle_flag(*format, *f))
				check_type(*format, *f);
		}
	}
	return (f->return_value);
}
int main()
{
	char c = 'a';
	int n = 10;

	ft_printf("!111");
	printf("1 >%*c<\n", n, c);
	printf("2 >%-*c<\n", n ,c);
	printf("3 >%*.c<\n", n ,c);
	printf("4 >%-c<\n", c);
	printf("5 >%-.c<\n", c);
	printf("6 >%.c<\n", c);
	printf("7 >%10.4c<\n", c);   // .뒤에 숫자 warning
	printf("8 >%.4c<\n", c);     // .뒤에 숫자, warning
	printf("9 >%.c<\n", c);
	printf("10>%0.0c<\n", c);    // warning
	printf("11>%0.c<\n", c);     // warning
	printf("12>%0c<\n", c);      // warning
}