/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/19 21:31:08 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> //malloc
# include <unistd.h> //read
# include <fcntl.h> //open
# include<stdio.h> //삭제하셈

char		*my_strdup(const char *s1);
char		*my_strjoin(char const *s1, char const *s2);
char		*my_substr(char const *s, unsigned int start, size_t len);
size_t		my_strlcpy(char *dest, char const *src, size_t size);
size_t		my_strlen(const char *str);
# endif

