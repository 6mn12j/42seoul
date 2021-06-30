/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:16:44 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/30 22:07:31 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_maxlength(t_flag *f, long long value, int is_minus)
{
	// printf("pre:%d\n",f->precision);
	//printf("pre_v:%d\n",f->precision_value);
	int result;

	//printf("maxlength_value:%lld\n",value);
	//printf("is_minus:%d\n",is_minus);
	//printf("widht:%d\n",f->width);

	if (f->precision && f->precision_value + is_minus > value )
		result = f->precision_value + is_minus;
	else if (f->zero == 1 && !f->precision && !f->minus)
		result = f->width >= value ?
f->width : value ;
	else
		result = value;
	//printf("result:%d\n",result);
	//printf("ft_digitlen:%zu\n",ft_digitlen(value));
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
	//printf("backup:%s\n",*backup);
	//printf("width_space:|%s|\n",width_space);
	if (f->minus)
		*backup = ft_strjoin(*backup, width_space);
	else
		*backup = ft_strjoin(width_space, *backup);
	if (!backup)
		return (0);
	//printf("backup:|%s|\n",*backup);
	my_free(tmp);
	my_free(width_space);
	return (1);
}

char			*ft_itoa(long long n)
{
	long long	num;
	char		*temp;
	size_t		len;

	num = n;
	len = 0;

	if (num < 0)
	{
		len = ft_digitlen(num) + 1;
		num = num * -1;
	}
	else if (num == 0)
		len = 1;
	else
		len = ft_digitlen(num);
	if (!(temp = malloc(sizeof(char) * len + 1)))
		return (0);
	temp[len] = '\0';
	while (len > 0)
	{
		temp[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		temp[0] = '-';
	return (temp);
}

int		ft_printf_num(t_flag *f, va_list *ap, char spec)
{
	int	num_len;
	int	is_minus;
	long long v;
	long long length;
	long long width_len;
	char *temp;
	char *backup;

	v = 0;
	
	if (spec == 'd' || spec == 'i')
	{
		v = va_arg(*ap, int);
		temp = ft_itoa(v);
	}
	else if (spec == 'u')
	{
		v = va_arg(*ap, unsigned int);
		temp = ft_itoa(v);
	}
	else if (spec == 'x')
	{
		v = va_arg(*ap, unsigned int);
		temp = ft_putnbr_base(v, "0123456789abcdef");
	}
	else if (spec == 'X')
	{
		v = va_arg(*ap, unsigned int);
		temp = ft_putnbr_base(v, "0123456789ABCDEF");
	}
	is_minus = v < 0 ? 1 : 0;
	num_len = ft_strlen(temp);
	length = find_maxlength(f, num_len, is_minus);
	if (f->precision && f->precision_value == 0 && v == 0)
		length = 0;
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	if (f->precision || f->zero)
		ft_memset(backup, '0', length);
	backup[length] = '\0';
	
	if (v < 0)
	{
		backup[0] = '-';
		v = v * -1;
	}
	//printf("backup:%s\n",backup);
	//printf("backup:%stemp:%stemp_len:%zu\n",backup,temp,ft_strlen(temp));
	if(backup[0] == '-')
		ft_strrcpy(backup,temp,ft_strlen(temp)-1);
	else
		ft_strrcpy(backup,temp,ft_strlen(temp));
	//printf("f->width:%d length:%lld\n",f->width,length);
	width_len = f->width - length;
	//printf("width_len:%lld\n",width_len);
	if (width_len > 0)
		make_width(&backup, f, width_len);
	//printf("backup:\n|%s|\n",backup);
	while (*backup)
	{
		f->return_value += write(1, backup, 1);
		backup++;
	}
	return (1);
}
