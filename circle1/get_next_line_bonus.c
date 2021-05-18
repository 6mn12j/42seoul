/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2021/05/18 01:53:42 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h> //OPEN MAX = 256

#define BUFFER_SIZE 10000
void	ft_free(char *str)
{
	if (str != NULL)
		free(str);
	str = 0;
}

char *ft_update()
{
	ft_strdup(&backup[fd] + i + 1);
		free(backup[fd]);
	return ()
}

void ft_free(char *str)
{
	if(!str)
		free(str);
	str = 0;
}

int *find_gnl(char *str)
{
	int i;

	i = 0;
	while (str[i] && str)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}


int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	int			i;
	int			nbytes;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (-1);
	while ((nbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buf[nbytes] = 0;
		temp = ft_strdup(buf);
		ft_free(buf);
		backup[fd] = ft_strjoin(temp, backup[fd]);
		ft_free(temp);
		while (backup[fd][i] != '\n' && backup[fd][i])
			i++;
		if (backup[fd][i] == '\n') //백업의 중간에 개행이 있는경우 ...........만 ..............
		{
			*line = substr(backup[fd], 0, i - 1);
			backup[fd] = ft_update;
			if (!backup[fd])
				return (-1);
			else
				return (1);
		}
		// 개행이 없는경우엔 그냥 와일로 넘겨
		//개행을 만나면 라인에 넣고 버퍼를 업데이트 해줘야됨 (라인에 넣은 후에 애들로)
	}

	//EOF 읽고 내려옴
	i = 0;
	while (backup[fd][i] != '\n' && backup[fd][i])
			i++;
	if (backup[fd][i] == '\n')
	{
		 // line에 넣어
		if(backup[fd][i + 1])
			//백업 업데이트 성공시 리턴1  . ? 아니면 마이너스 1
		else
			ft_free(backup[fd]);
			//백업 프리 하고  끝내
	}
	else
	{
		*line = substr(backup[fd], 0, i - 1);
		free(backup[fd]);
		if (!line)
			return (-1);
		else
			return (0);
	}
	//버퍼사이즈만큼 읽어서 갖다 붙혀 그다음에 개행을 확인해 그런데 개행이있따 ? 그러면 이제 라인에 개행전까지 넣고 개행후값을 어디다가 옮겨서 그 버퍼를 free
}
/*
ASDFASDFASDF \N ASDFFASDFASDF
*/
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("your_file_name", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\\n", line);
		free(line);
	}
	printf("%s\\n", line);
	free(line);
	return (0);
}