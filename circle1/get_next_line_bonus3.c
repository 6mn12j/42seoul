/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:10:59 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/19 22:28:09 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_netxt_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
# endif

int		my_free(char *str)
{
	if(!str)
		free(str);
	str = 0;
	return (-1);
}

int		get_next_line_bonus3(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			nbytes;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((nbytes = read(fd, buf, BUFFER_SIZE) > 0))
	{
		buf[nbytes]=0;
		temp = backup[fd];
		backup[fd] = my_strjoin(backup[fd], buf);
		if (!backup[fd])
			return (-1);
		my_free(temp);
		if ()

	}

	return (my_read_line(backup[fd], fd, line));
}