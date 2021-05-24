/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:10:59 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/24 20:57:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		my_strchr(const char *s, int c)
{
	unsigned char	target;
	int				i;

	target = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return (i);
		i++;
	}
	if (s[i] == target)
		return (i);
	return (-1);
}

static int		my_free(char *str)
{
	free(str);
	str = 0;
	return (1);
}

static int		handle_fin_line(char **backup, char *temp, char **line, int fd)
{
	*line = my_strdup(backup[fd]);
	my_free(temp);
	backup[fd] = 0;
	return (0);
}

static int		my_read_line(char **backup, char **line, int fd, char *buf)
{
	char	*temp;
	int		i;

	temp = backup[fd];
	if ((i = my_strchr(backup[fd], '\n')) == -1)
		handle_fin_line(backup, temp, line, fd);
	if (backup[fd])
	{
		*line = my_substr(backup[fd], 0, i);
		if ((backup[fd])[i + 1])
		{
			my_free(buf);
			backup[fd] = my_strdup(backup[fd] + i + 1);
			return (my_free(temp));
		}
		else
		{
			my_free(buf);
			backup[fd] = my_strdup("");
			return (my_free(temp));
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		*buf;
	char		*temp;
	int			nbytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (my_free(buf) * -1);
	if (!backup[fd])
		backup[fd] = my_strdup("");
	while ((nbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nbytes] = 0;
		temp = backup[fd];
		backup[fd] = my_strjoin(backup[fd], buf);
		my_free(temp);
		if (my_strchr(backup[fd], '\n') != -1)
			return (my_read_line(backup, line, fd, buf));
	}
	if (nbytes < 0)
	{
		my_free(buf);
		return (-my_free(backup[fd]));
	}
	return (my_free(buf) * my_read_line(backup, line, fd, buf));
}
