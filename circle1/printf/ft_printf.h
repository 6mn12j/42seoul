/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:40:15 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/29 20:21:31 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef FT_PRINTF_H
 # define FT_PRINTF_H

 #include <unistd.h>
 #include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>

typedef struct s_flag
{
	 int zero;
	 int minus;
	 int width;
	 int precision;
	 int precision_value;
	 int return_value;

	 char spec;
}			t_flag;



int		is_spec(const char c);
int		ft_printf_num(t_flag *f, va_list *ap, char spec);
void	init_flag(t_flag *f);
int		find_maxlength(t_flag *f, long long value);
int		ft_printf(const char *format, ...);
int		find_length(int length, int value, t_flag *f);
int		str_len(char *base);
int		get_flag_num(const char **format, va_list *ap);
int		handle_flag(const char **format, t_flag *f, va_list *ap);
int		make_width(char **backup, t_flag *f, int width_len);
void	clear_flag(t_flag *f);

int		ft_isdigit(char c);
int		str_len(char *base);
int		handle_hex(long long num);
char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_memset(void *dest, int value, size_t len);
void	*ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr_base(long long  nbr, char *base);
void	handle_base(long long  nbr, char *base);
size_t		ft_strlen(const char *str);
size_t		ft_digitlen(long long value);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
#endif