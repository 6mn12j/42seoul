/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:41:36 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/09 02:21:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void			*ft_bzero(void *dest, size_t len);
void			*ft_memset(void *dest, int value, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int target, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putstr_fd(char *str, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *str, int fd);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int num);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
unsigned int	ft_strlcpy(char *dest, char const *src, size_t size);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
#endif
