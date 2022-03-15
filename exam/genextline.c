#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int recurse(char **line, int fd, int idx)
{
    char buf;
    int ret;
    int rd;

    rd = read(fd, &buf, 1);
    if (rd == 0)
    {
        *line = (char*)malloc(sizeof(char) * (idx + 1));
        (*line)[idx] = 0;
        return (0);
    }
    if (buf == '\n')
    {
        *line =(char*)malloc(sizeof(char) * (idx + 1));
        (*line)[idx] = 0;
        return (1);
    }
    else if (rd == 1)
    {
        ret = recurse(line, fd, idx + 1);
        (*line)[idx] = buf;
		if (ret == -1)
			return (-1);
        return (1);
    }
    else
        return (-1);
}
char *gnl(int fd)
{
	char *line;
	int	ret;

	ret = 0;
	ret = recurse(&line, fd, 0);

	if (ret >= 1)
		return (line);
	if (ret <= 0)
		return (NULL);
    return (line);
}

int main()
{
    char *str;

    str = 0;
    while (1)
	{
	    str = gnl(0);
		if (!str)
		{
            printf("EOF\n");
        }
		else
			printf("%s\n", str);
	}
    return (1);
}
