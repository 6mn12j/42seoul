#include <unistd.h>
void ft_union(char *s1, char *s2)
{
	int asci[256];
	int i = 0;
	while (i < 256)
		asci[i++] = 0;
	while (*s1)
	{
		if (!asci[(int)(*s1)])
		{
			write(1, s1, 1);
		}
		++s1;
	}
	while (*s2)
	{
		if (!asci[(int)(*s2)])
		{
			write(1, s2, 1);
			asci[(int)(*s2)] = 1;
		}
		++s2;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1],argv[2]);
	write(1, "\n", 1);

}
