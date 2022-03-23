/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:10:59 by minjupar          #+#    #+#             */
/*   Updated: 2022/03/23 02:21:47 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"
#include "../../include/so_long.h"

char *gnl(int fd,int width)
{
    int i;
    char *line;
    char buf;

    line = malloc(sizeof(char) * width);
    line[0]=0;

    buf = 0;
    i = 0;
    while(read(fd, &buf, 1) == 1)
    {
        if (buf == '\n')
        {
            i++;
            break;
        }
        line[i++] = buf;
    }
    if(line[0]==0)
        return(0);
    line[width] = 0;
    return (line);
}
