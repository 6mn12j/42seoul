/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:10:59 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/21 04:56:34 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
# endif

static int		my_strchr(const char *s, int c)
{
	unsigned char target;
	int i;

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
	if(str)
	{
		free(str);
		str = 0;
	}
	return (1);
}

static int		my_read_line(char **backup, char **line ,int fd)
{
	char *temp;
	int	i;

	i = my_strchr(backup[fd], '\n');
	if (i == -1)
	{
		temp = backup[fd];
		*line = my_strdup(backup[fd]);
		my_free(temp);
		backup[fd] = 0;
		return (0);
	}
	if (backup[fd])
	{
		*line = my_substr(backup[fd], 0, i);
		temp = backup[fd];
		if ((backup[fd])[i + 1])
		{
			backup[fd] = my_strdup(backup[fd] + i + 1);
			my_free(temp);
			return (1);
		}
		else
		{
			backup[fd] = my_strdup("");
			my_free(temp);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			nbytes;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	if(!backup[fd])
		backup[fd] = my_strdup("");
	while ((nbytes = read(fd, buf, BUFFER_SIZE) ) > 0)
	{
		printf("%d\n",nbytes);
		buf[nbytes]=0;
		temp = backup[fd];
		backup[fd] = my_strjoin(backup[fd], buf);
		my_free(temp);
		if (my_strchr(backup[fd], '\n') != -1)
			return(my_read_line(backup, line, fd));
	}
	if(nbytes < 0)
	{
		my_free(backup[fd]);
		return (-1);
	}
	return (my_read_line(backup, line, fd));
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		//printf("return: %d\n",ret);
		free(line);
	}
	printf("%s\n", line);
	//printf("return: %d\n",ret);
	free(line);
	return (0);
}