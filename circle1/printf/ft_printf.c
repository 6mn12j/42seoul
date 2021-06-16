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

void		handle_flag(const char *format)
{
	printf("handle flag");
}

int wtf_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
	 return (1);

	return (-1);
}

int ft_printf(const char *format, ...)
{
	int i;
	int length;
	int return_value;
	va_list ap;

	va_start(ap, *format);
	i = 0;
	return_value = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			write(1, format[i++], 1);
			return_value++;
			break ;
		}
		else if (wtf_type(format[i]))
		{
			handle_flag(*format);
			break;
		}
		i++;

	}
	return (return_value);
}

int main()
{
	char c = 'a';
	int n = 10;

	ft_printf("!111");
	printf("1 >%*c<\n", n, c);
	printf("2 >%-*c<\n", n, c);
	printf("3 >%*.c<\n", n, c);
	printf("4 >%-c<\n", c);
	printf("5 >%-.c<\n", c);
	printf("6 >%.c<\n", c);
	printf("7 >%10.4c<\n", c);   // .뒤에 숫자 warning
	printf("8 >%.4c<\n", c);     // .뒤에 숫자, warning
	printf("9 >%.c<\n", c);
	printf("10>%0.0c<\n", c);    // warning
	printf("11>%0.c<\n", c);     // warning
	printf("12>%0c<\n", c);      // warning
}