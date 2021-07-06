/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:40:02 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/04 14:46:37 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_maxlength(t_flag *f, long long value)
{
	int		result;

	value = f->spec == 'p' ? value + 2 : value;
	if (f->precision && f->precision_value + f->is_minus > value + f->is_minus)
		result = f->precision_value + f->is_minus;
	else if (f->zero == 1 && !f->precision && !f->minus)
		result = f->width >= value + f->is_minus ? f->width :
		value + f->is_minus;
	else
		result = value + f->is_minus;
	return (result);
}

int		make_width(char **backup, t_flag *f, int width_len)
{
	char		*width_space;
	char		*tmp;
	long long	i;

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
	my_free(&tmp);
	my_free(&width_space);
	return (1);
}

char	*get_value(t_flag *f, va_list *ap)
{
	if (f->spec == 'd' || f->spec == 'i')
		return (ft_itoa(va_arg(*ap, int), f));
	else if (f->spec == 'u')
		return (ft_itoa(va_arg(*ap, unsigned int), f));
	else if (f->spec == 'x')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (f->spec == 'X')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (f->spec == 'p')
		return (ft_putnbr_base((unsigned long long)va_arg(*ap, void*),
		"0123456789abcdef"));
		return (0);
}

void	handle_precision_non(t_flag *f, char *temp, int *length)
{
	if (f->spec == 'p' && f->precision && f->precision_value == 0
	&& *temp == '0')
	{
		*length = 2;
		temp[0] = '\0';
	}
	else if (f->precision && f->precision_value == 0 && *temp == '0')
	{
		*length = 0;
		temp[0] = '\0';
	}
	return ;
}

int		ft_printf_num(t_flag *f, va_list *ap)
{
	int		length;
	char	*temp;
	char	*backup;

	temp = get_value(f, ap);
	length = find_maxlength(f, ft_strlen(temp));
	handle_precision_non(f, temp, &length);
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	if (f->precision || f->zero)
		ft_memset(backup, '0', length);
	backup[length] = '\0';
	backup[0] = f->is_minus ? '-' : backup[0];
	ft_strrcpy(backup, temp, ft_strlen(temp));
	if (f->spec == 'p')
	{
		backup[0] = '0';
		backup[1] = 'x';
	}
	if (f->width - length > 0)
		make_width(&backup, f, f->width - length);
	f->return_value += write(1, backup, ft_strlen(backup));
	my_free(&temp);
	return (my_free(&backup));
}
