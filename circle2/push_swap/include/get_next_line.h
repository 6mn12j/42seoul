/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/14 17:38:17 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char		*my_strdup(const char *s1);
char		*my_strjoin(char const *s1, char const *s2);
char		*my_substr(char const *s, unsigned int start, size_t len);
size_t		my_strlcpy(char *dest, char const *src, size_t size);
size_t		my_strlen(const char *str);
int			get_next_line(int fd, char **line);
#endif
