/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:47:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/21 22:00:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

#include <unistd.h>
int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	init_flag(t_flag *f)
{
	f->zero = -1;
	f->minus = -1;
	f->width = 0;
	f->precision = 0;
	f->precision_value = 0;
	f->return_value = 0;
	f->spec = 0;
}

int		is_spec(const char c)
{
	if (c == 'c' || c == 's' ||
		c == 's' || c == 'd' ||
		c == 'i' || c == 'u' ||
		c == 'x' || c == 'X')
		return (1);
	return (-1);
}

int		get_flag_num(const char **format, va_list ap)
{
	int num;

	num = 0;
	if (**format == '*')
		num = va_arg(ap, int);
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
			f->precision_value = (get_flag_num(format, ap));
	}
	if (is_spec(**format))
	{
		f->spec = **format;
		return (1);
	}

	return (-1);
}

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (len--)
		ptr[len] = (unsigned char)value;
	return (dest);
}

void	*ft_bzero(void *dest, size_t len)
{
	return (ft_memset(dest, 0, len));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size * count)))
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}

int		digitlen(int value)
{
	int		l;

	l = 0;
	while (value)
	{
		value = value / 10;
		l++;
	}
	return (l);
}

int		find_length(int length, int value, t_flag *f)
{
	int		maxlength;
	int		v_length;
	char	*temp;

	v_length = digitlen(value);
	maxlength = f->width > f->precision ? f->width : f->precision;
	maxlength = maxlength > v_length ? maxlength : v_length;
	if (f->zero != -1)
		temp = (char *)ft_calloc(maxlength, sizeof(char));
	else
		temp = (char *)malloc(sizeof(char) * (maxlength + 1));

	printf("width: %d maxlength: %d\n", f->width, maxlength);
	temp[maxlength] = '!';
	printf("|temp : %s|\n",temp);
	while (v_length && *temp)
	{
		printf("!!!\n");
		temp[v_length--] = (value % 10) - '0';
		value = value / 10;
	}
	printf("%s",temp);
	return (0);

}

void	ft_printf_d(const char **format, t_flag *f, va_list ap)
{
	int v;
	int length;
	char backup;

	length = 0;
	v = va_arg(ap, int);

	find_length(length, v, f);

	return ;
}

void	ft_printf_i(const char **format, t_flag *f, va_list ap)
{
	printf("i");
	return ;
}

void	clear_flag(t_flag *f)
{

}

int		ft_printf(const char *format, ...)
{
	int length;
	va_list ap;

	va_start(ap, format);
	t_flag f;
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
			if (handle_flag(&format, &f, ap) == 1)
			{
				clear_flag(&f);
				if (*format == 'd')
				 	ft_printf_d(&format, &f, ap);
				else if (*format == 'i')
				 	ft_printf_i(&format, &f, ap);
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

int		main()
{
	//int return1 = printf("|%04.d|\n",3);
	//int return2 = ft_printf("|%04.d|\n",3);
	//int return3 = printf("|%-010.4d|\n",3);
	//int return4 = ft_printf("|%010.4d|\n",3);
	//printf("---프리시전에 * 카드로 음수가 들어올때 ---\n");
	//int return5 = printf("|%010.*d|\n",-3, 3);
	//int return6 = ft_printf("|%010.*d|\n",-3, 3);
	//printf("\n-----프리시전에 그냥 음수 들어올 때-----\n");
	//int return7 = printf("|%010.-3d|\n",3);
	//int return8 = ft_printf("|%010.-3d|\n",3);
	//printf("--------------------------\n");
	//printf("return 1: %d\n", return1);
	//printf("return 2: %d\n", return2);
	//printf("return 3: %d\n", return3);
	//printf("return 4: %d\n", return4);
	printf("\n-------------------------\n");
	printf("1: |%010.5d|\n",12);
	ft_printf("1: |%010.5d|\n",12);
	printf("\n-------------------------\n");
	printf("2: |%-101.51d|\n",3);
	ft_printf("2: |%-101.51d|\n",3);
	printf("\n-------------------------\n");
	printf("3: |%101.-51d|\n",3);
	ft_printf("3: |%101.-51d|\n",3);
	printf("\n--------------------------\n");
	printf("4: |%10.*d|\n",5,3);
	ft_printf("4: |%10.*d|\n",5,3);
	printf("\n--------------------------\n");
	printf("5: |%*.5d|\n",10,3);
	ft_printf("5: |%*.5d|\n",10,3);
	printf("\n--------------------------\n");
	printf("6: |%*.*d|\n",10,5,3);
	ft_printf("6: |%*.*d|\n",10,5,3);
	printf("\n--------------------------\n");
	printf("7: |%*.*d|\n",123,123,123);
	ft_printf("7: |%*.*d|\n",123,123,123);
	printf("\n--------------------------\n");
	printf("8: |%010d|\n",12345);
	ft_printf("8: |%010d|\n",12345);
	printf("\n--------------------------\n");
	printf("8: |%010|\n",12345);
	ft_printf("8: |%010|\n",12345);

		// printf("\n-------------\n");
		// printf("zero : %d\n", f->zero);
		// printf("minus : %d\n", f->minus);
		// printf("width : %d\n", f->width);
		// printf("precision : %d\n", f->precision);
		// printf("precision_v : %d\n", f->precision_value);
		// printf("spec : %c\n", f->spec);






}
