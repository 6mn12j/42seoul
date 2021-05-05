/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:41:36 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/05 22:53:55 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

void			*ft_bzero(void *dest, size_t len);
void			*ft_memset(void *dest, int value, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int target, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int num);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
int				ft_strlen(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlcpy(char *dest, char const *src, size_t size);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
#endif
