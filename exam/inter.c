#include <unistd.h>

void inter(char *s1, char *s2)
{
	int asci[256];
	int i = 0;
	while (i < 255)
		asci[i++] = 0;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (!asci[(int)(*s1)] && *s1 == s2[i])
			{
				write(1, s1, 1);
				asci[(int)(*s1)] = 1;
				break;
			}
			i++;
		}
		++s1;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1],argv[2]);
	write(1, "\n", 1);
	return (0);
}
