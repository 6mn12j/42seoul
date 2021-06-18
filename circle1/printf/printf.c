#include <stdio.h>

int		main(void)
{
	printf("|%04d.3|\n",3);
	printf("|%.0d|\n",3);
	printf("|%10.4d|\n",3);
	printf("|%10.4d|\n",-3);
	printf("|%0.4d|\n",-3);
	printf("|%-10d|\n",3);
	printf("|%-10.2d|\n",3);
	printf("|%0-10.3d|\n",3);
}
