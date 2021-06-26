/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:40:15 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/26 20:28:10 by minjupar         ###   ########.fr       */
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


int		digitlen(int value);
int		is_spec(const char c);
int		ft_printf_d(t_flag *f, va_list ap);
void	init_flag(t_flag *f);
int		find_maxlength(t_flag *f, int value);
int		ft_printf(const char *format, ...);
int		find_length(int length, int value, t_flag *f);
int		get_flag_num(const char **format, va_list ap);
int		handle_flag(const char **format, t_flag *f, va_list ap);
void	clear_flag(t_flag *f);
void	make_width(char **backup, t_flag *f, int width_len);

int		ft_isdigit(char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *dest, int value, size_t len);
void	*ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
#endif