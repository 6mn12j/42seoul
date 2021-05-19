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

int		*ft_strchr(const char *s, int c)
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
	return (0);
}

int		my_free(char *str)
{
	if(!str)
		free(str);
	str = 0;
	return (1);
}

int		my_read_line(char **backup, int fd, char **line ,int i)
{
	char *temp;

	backup[fd][i] = 0;
	if (backup[fd])
	{
		*line = my_substr(backup[fd], 0, i);
		temp = backup[fd];
		if (backup[fd + 1])
		{
			backup[fd] = my_strdup(backup[fd] + i + 1);
			if (!backup[fd])
				return (my_free(temp));
		}
		else
			return (my_free(temp));
	}
	*line = my_strdup(""); //backup이 없는데 eof
	my_free(backup[fd]);
	return (0);
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
		free(temp);
		if (!backup[fd])
			return (-1);
		if ((i = my_strchar(backup[fd], '\n')))
			my_read_line(backup[fd], fd, line, i);
	}
	if(nbytes < 0)
		return (-1);
	i = my_strchr(backup[fd], '\n');
	return (my_read_line(backup[fd], fd, line, i));
}