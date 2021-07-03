/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:16:44 by minjupar        #+#    #+#             */
/*   Updated: 2021/07/02 20:16:59 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
extern int m_cnt;
extern int f_cnt;
int		find_maxlength(t_flag *f, long long value)
{
	int		result;
	//printf("%lld\n",value);
	value = f->spec == 'p' ? value + 2 : value ;
	if (f->precision && f->precision_value + f->is_minus > value + f->is_minus)
		result = f->precision_value + f->is_minus;
	else if (f->zero == 1 && !f->precision && !f->minus)
		result = f->width >= value + f->is_minus ? f->width : value + f->is_minus;
	// else if (value == 0 || f->width)
	// 	result = f->width;
	else
		result = value + f->is_minus;
	return (result);
}

int		my_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
		f_cnt++;
		//printf("free:%d\n",f_cnt);
	}
	return (1);
}

char	*ft_putnbr_base(unsigned long long  nbr, char *base)
{
	char *str;
	int		i;
	long long		num;

	num = nbr;
	i = 0;
	if (nbr == 0)
	{
		// str = (char*)malloc(sizeof(char) * 2);
		str = my_alloc(1);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (num)
	{
		if (num == 0)
			break;
		num = num / 16;
		i++;
	}
	//printf("i: %d\n",i);
	// str = (char*)malloc(sizeof(char) * (i + 1));
	str = my_alloc(i);
	str[i] = '\0';
	while (nbr)
	{
		if (i < 0)
			break ;
		str[--i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*dest;

	if (!s1 || !s2)
		return (0);
	//printf("join0 m:%d f:%d temp:|%s| %p",m_cnt,f_cnt,temp,temp);
	s1_len = ft_strlen(s1);
	//printf("join0 m:%d f:%d s1:|%s|%p s2:|%s|%p",m_cnt,f_cnt,s1,s1,s2,s2);
	s2_len = ft_strlen(s2);
//	printf("join1 s1:%zu s2:%zu\n",s1_len, s2_len);
	// if (!(temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
	if (!(dest = my_alloc(s1_len + s2_len)))
		return (0);
	dest[s1_len + s2_len] = '\0';
	//printf("join2 m:%d f:%d temp:|%s| %p",m_cnt,f_cnt,dest,dest);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(&dest[s1_len], s2, s2_len + 1);
	//printf("koin3 m:%d f:%d temp:|%s| %p",m_cnt,f_cnt,temp,temp);
	return (dest);
}

char	*my_alloc(int len)
{
	m_cnt++;
	char * dest;
	//printf("malloc:%d\n",m_cnt);
	//printf("mlloc_len:%d\n",len);
	//printf("malloc:%p\n",dest);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	return (dest);
}

int		make_width(char **backup, t_flag *f, int width_len)
{
	char *width_space;
	char *tmp;
	long long i;
	i = 0;
	tmp = *backup;
	// width_space = (char *)malloc(sizeof(char) * (width_len + 1));
	width_space = my_alloc(width_len);
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
	//printf("m%df%d backup:|%s| %p",m_cnt,f_cnt,*backup,*backup);
	my_free(&tmp);
	my_free(&width_space);
	return (1);
}

char	*ft_itoa(long long n, t_flag *f)
{
	long long num;
	char *temp;
	size_t len;

	num = n;
	len = 0;

	if (num < 0)
	{
		len = ft_digitlen(num);
		num = num * -1;
	}
	else if (num == 0)
		len = 1;
	else
		len = ft_digitlen(num);
	// if (!(temp = malloc(sizeof(char) * len + 1)))
	if (!(temp = my_alloc(len)))
		return (0);
	temp[len] = '\0';
	while (len > 0)
	{
		temp[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		f->is_minus = 1;
	return (temp);
}

// int		ft_printf_num(t_flag *f, va_list *ap)
// {
// 	int		num_len;
// 	int		is_minus;
// 	long long v;
// 	long long length;
// 	long long width_len;
// 	char *temp;
// 	char *backup;

// 	v = 0;
// 	if (f->spec == 'd' || f->spec == 'i')
// 	{
// 		v = va_arg(*ap, int);
// 		temp = ft_itoa(v);
// 	}
// 	else if (f->spec == 'u')
// 	{
// 		v = va_arg(*ap, unsigned int);
// 		temp = ft_itoa(v);
// 	}
// 	else if (f->spec == 'x')
// 	{
// 		v = va_arg(*ap, unsigned int);
// 		temp = ft_putnbr_base(v, "0123456789abcdef");
// 	}
// 	else if (f->spec == 'X')
// 	{
// 		v = va_arg(*ap, unsigned int);
// 		temp = ft_putnbr_base(v, "0123456789ABCDEF");
// 	}
// 	is_minus = v < 0 ? 1 : 0;
// 	num_len = ft_strlen(temp);
// 	length = find_maxlength(f, num_len, is_minus);
// 	if (f->precision && f->precision_value == 0 && v == 0)
// 		length = 0;
// 	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
// 		return (0);
// 	if (f->precision || f->zero)
// 		ft_memset(backup, '0', length);
// 	backup[length] = '\0';
// 	if (v < 0)
// 	{
// 		backup[0] = '-';
// 		v = v * -1;
// 	}
// 	if (backup[0] == '-')
// 		ft_strrcpy(backup, temp, ft_strlen(temp) - 1);
// 	else
// 		ft_strrcpy(backup, temp, ft_strlen(temp));
// 	//my_free(temp);
// 	// if (f->spec == 'p')
// 	// {
// 	// 	temp = backup;
// 	// 	backup = ft_strjoin("0x", backup);
// 	// 	length += 2;
// 	// 	my_free(&temp);
// 	// }
// 	width_len = f->width - length;
// 	if (width_len > 0)
// 		make_width(&backup, f, width_len);
// 	f->return_value += write(1, backup, ft_strlen(backup));
// 	my_free(&backup);
// 	return (1);
// }

int		ft_printf_num(t_flag *f, va_list *ap)
{
	long long length;
	long long width_len;
	char *temp;
	char *backup;

	temp = 0;
	if (f->spec == 'd' || f->spec == 'i')
		temp = ft_itoa(va_arg(*ap, int), f);
	else if (f->spec == 'u')
		temp = ft_itoa(va_arg(*ap, unsigned int), f);
	else if (f->spec == 'x')
		temp =ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef");
	else if (f->spec == 'X')
		temp = ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	else if (f->spec == 'p')
		temp = ft_putnbr_base((unsigned long long)va_arg(*ap, void*),"0123456789abcdef");
	length = find_maxlength(f, ft_strlen(temp));
	if (f->precision && f->precision_value == 0 && *temp == '0')
		length = 0;
	//printf("length:%lld\n",length);
	//printf("temp:%s\n",temp);
	// if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
	if (!(backup = my_alloc(length)))
		return (0);
	if (f->precision || f->zero)
		ft_memset(backup, '0', length);
	//printf("!1 backup:%p\n",backup);
	if (f->is_minus)
		backup[0] = '-';
	backup[length] = '\0';

//	printf("!2 backup:|%s|%p\n",backup, backup);
//	printf("temp:|%s|%p\n",temp,temp);
	if (backup[0] == '-')
		ft_strrcpy(backup, temp, ft_strlen(temp));
	else
		ft_strrcpy(backup, temp, ft_strlen(temp));
//	printf("backup:|%s| temp:|%s| %zu\n",backup,temp,ft_strlen(temp));
	if (f->spec == 'p')
	{
		backup[0] = '0';
		backup[1] = 'x';
	}
//	printf("backup:|%s|\n",backup);
	//printf("!3 backup:%p\n",backup);
//	my_free(&temp);
	// if (f->spec == 'p')
	// {
	// 	temp = backup;
	// 	backup = ft_strjoin("0x", backup);
	// 	length += 2;
	// 	my_free(&temp);
	// }
//	printf("!4 backup:%s backup:%p width:%d\n", backup, backup, f->width);
	if (f->spec == 'p' && f->precision && f->precision_value == 0 && *temp == '0')
		length = 2;
	width_len = f->width - length;
	if (width_len > 0)
		make_width(&backup, f, width_len);
	//printf("!5 backup:%p\n",backup);
	f->return_value += write(1, backup, ft_strlen(backup));
	my_free(&temp);
	my_free(&backup);
	//printf("free:%d mlloc:%d\n",f_cnt, m_cnt);
	return (1);
}



// int		ft_printf_num_p(t_flag *f, va_list *ap)
// {
// 	int					num_len;
// 	//int					is_minus;
// 	unsigned long long	v;
// 	long long			length;
// 	long long			width_len;
// 	char				*temp;
// 	char				*backup;

// 	v = (unsigned long long)va_arg(*ap, void*);
// 	temp = ft_putnbr_base(v, "0123456789abcdef");
// //	is_minus = v < 0 ? 1 : 0;
// 	num_len = ft_strlen(temp);

// 	length = find_maxlength(f, num_len);
// 	if (f->precision && f->precision_value == 0 && v == 0)
// 		length = 0;
// 	if (!(backup = (char *)malloc(sizeof(char) * (length + 1))))
// 		return (0);
// 	if (f->precision || f->zero)
// 		ft_memset(backup, '0', length);
	
// 	backup[length] = '\0';
// 	if (v < 0)
// 	{
// 		backup[0] = '-';
// 		v = v * -1;
// 	}
// 	if (backup[0] == '-')
// 		ft_strrcpy(backup, temp, ft_strlen(temp) - 1);
// 	else
// 		ft_strrcpy(backup, temp, ft_strlen(temp));
// 	my_free(&temp);
// 	if (f->spec == 'p')
// 	{
// 		temp = backup;
// 		backup = ft_strjoin("0x", backup);
// 		length += 2;
// 		my_free(&temp);
// 	}
// 	width_len = f->width - length;
// 	if (width_len > 0)
// 		make_width(&backup, f, width_len);
// 	if (f->is_minus)
// 		backup[0] = '-';
// 	f->return_value += write(1, backup, ft_strlen(backup));
// 	my_free(&backup);

// 	return (1);
// }
