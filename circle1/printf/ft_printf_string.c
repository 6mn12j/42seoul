/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:54:22 by minjupar          #+#    #+#             */
/*   Updated: 2021/07/01 20:42:17 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_strmaxlength(t_flag *f,int	str_len)
{
	int	result;

	result = 0;
	if (f->spec != 'c' && f->precision && f->precision_value < str_len)
		result = f->precision_value;
	else if (f->spec != 'c' && f->precision && f->precision_value > str_len)
		result = str_len;
	else if (f->spec != 'c' && f->precision && f->precision_value == 0)
		result = 0;
	else
		result = str_len;
	return (result);
}

int		ft_printf_string(t_flag *f, char *v)
{
	char *backup;
	int	str_len;
	int	length;
	if (v == NULL)
		v = "(null)";
	str_len = ft_strlen(v);
	length = find_strmaxlength(f, str_len);
//	printf("str_len:%d\nlength%d\n",str_len,length);
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	backup[length] = '\0';
	f->spec == 'c' ? backup[0] = v[0] : ft_strlcpy(backup, v, length + 1);
	//printf("f->width:%d\n",f->width);
	//printf("length:%d\n",length);
	if (f->spec == 'c' && backup[0] == 0 && f->width > 0)
		f->width -= 1;
	if (f->width - length > 0)
		make_width(&backup, f, f->width - length);
	while (*backup)
	{
		f->return_value += write(1, backup, 1);
		backup++;
	}
	return (1);
}
int		ft_printf_string_c(t_flag *f, char v)
{
	char *backup;
	int	length;

	length = 1;
	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	backup[length] = '\0';
	backup[0] = v;
	// printf("f->width:%d\n",f->width);
	// printf("length:%d\n",length);
	// if (f->spec == 'c' && backup[0] == 0 && f->width > 0)
	// 	f->width -= 1;
	if (f->width - length > 0)
		make_width(&backup, f, f->width - length);
	while (*backup)
	{
		f->return_value += write(1, backup, 1);
		backup++;
	}
	return (1);
}