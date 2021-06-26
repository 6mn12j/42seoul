#include "ft_printf.h"

int		main(void)
{

	int d =12;
	int a=ft_printf("-->|%0d|<--\n", -135);
	int b= printf("-->|%0d|<--\n", -135);
	printf("%d %d\n",a,b);
	printf("--------------------\n");
	ft_printf("%4d\n", 12);
	printf("%4d\n", 12);
	printf("--------------------\n");
	printf("|%04d|\n",3);
	ft_printf("|%04d|\n",3);
	printf("--------------------\n");
	printf("|%04d|\n",123);
	ft_printf("|%04d|\n",123);
	printf("--------------------\n");
	printf("|%010d|\n",3);
	ft_printf("|%010d|\n",3);
	printf("--------------------\n");
	printf("|%04.d|\n",3);
	ft_printf("|%04.d|\n",3);
	printf("--------------------\n");
	printf("|%010d|\n",3);
	ft_printf("|%010d|\n",3);
	printf("--------------------\n");
	printf("|%-04d|\n",3);
	ft_printf("|%-04d|\n",3);
	printf("--------------------\n");
	printf("|%-010d|\n",3);
	ft_printf("|%-010d|\n",3);
	printf("--------------------\n");
	printf("|%010.2d|\n",3);
	ft_printf("|%010.2d|\n",3);
	printf("--------------------\n");
	printf("|%0.0d|\n",3);
	ft_printf("|%0.0d|\n",3);
	printf("--------------------\n");
	printf("|%010.4d|\n",3);
	ft_printf("|%010.4d|\n",3);
	printf("--------------------\n");
	printf("|%010.4d|\n",-3);
	ft_printf("|%010.4d|\n",-3);
	printf("--------------------\n");
	printf("-5:|%0.4d|\n",-3);
	ft_printf( "-5:|%0.4d|\n",-3);
	printf("--------------------\n");
	printf("-4:|%0-10d|\n",3);
	ft_printf("-4:|%0-10d|\n",3);
	printf("--------------------\n");
	printf("-3:|%0-4d|\n",12345);
	ft_printf("-3:|%0-4d|\n",12345);
	printf("--------------------\n");
	printf("-2:|%010d|\n",3);
	ft_printf("-2:|%010d|\n",3);
	printf("--------------------\n");
	printf("|%0-10.2d|\n",3);
	ft_printf("|%0-10.2d|\n",3);
	printf("--------------------\n");
	printf("|%0-10.3d|\n",3);
	ft_printf("|%0-10.3d|\n",3);
	printf("--------------------\n");
	printf("|%010.3d|\n",12345);
	ft_printf("|%010.3d|\n",12345);
	printf("--------------------\n");
	printf("|%-010.3d|\n",12345);
	ft_printf("|%-010.3d|\n",12345);
	printf("--------------------\n");
	printf("|%-010.3d|\n",12);
	ft_printf("|%-010.3d|\n",12);
	printf("--------------------\n");
	printf("|%*.*d|\n",3,2-12);
	ft_printf("|%*.*d|\n",3,2-12);


}
