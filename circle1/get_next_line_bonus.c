/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:34:57 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/19 22:24:11 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
# endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
# endif

int		my_free(char *str)
{
	int i;

	i = 0;
	if (!str)
		free(str);
	str = 0;
	return (-1);
}

int	my_read_line(int fd, char **backup)
{
	int i;

	i = 0;
	while (backup[fd][i])
	{
		if (backup[fd][i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			nbytes;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((nbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nbytes] = 0;
		temp = backup[fd];
		backup[fd] = my_strjoin(backup[fd], buf);
		my_free(temp);
		if(!backup[fd])
			return (-1);
		if ((i = my_read_line(fd, backup)) >= 0)
		{
			backup[fd][i] = 0;
			*line = my_substr(backup[fd], 0 , i);
			temp = backup[fd];
			if (backup[fd][i + 1])
			{
				if(!(backup[fd] = my_strdup(backup[fd] + i + 1)))
					return (my_free(backup[fd]));
				return (1);
			}
			else
				return (-my_free(backup[fd]));
		}
	}
	if (nbytes == -1)
		return (-1);
	if (backup[fd]) // 여기서도 개행 검사.
	{
		if ((i = my_read_line(fd, backup)) >= 0)
		{
			backup[fd][i] = 0;
			*line = my_substr(backup[fd], 0 , i);
			temp = backup[fd];
			if (backup[fd][i + 1])
			{
				if(!(backup[fd] = my_strdup(backup[fd] + i + 1)))
					return (my_free(backup[fd]));
				return (1);
			}
			else
				return (-my_free(backup[fd]));
		}
		*line = my_strdup(backup[fd]);
		return (my_free(backup[fd]));
	}
	*line =my_strdup(""); // backup이 없는데 eof.
	my_free(backup[fd]);
	return (0);
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("test.txt", O_RDONLY);
	//ret = get_next_line(fd, &line);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
