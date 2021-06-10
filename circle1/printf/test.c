#include <stdio.h>

int main()
{
	char c = 'a';
	int n = 10;

	printf("1 >%*c<\n", n, c);
	printf("2 >%-*c<\n", n, c);
	printf("3 >%*.c<\n", n, c);
	printf("4 >%-c<\n", c);
	printf("5 >%-.c<\n", c);
	printf("6 >%.c<\n", c);
	printf("7 >%10.4c<\n", c);   // .뒤에 숫자 warning
	printf("8 >%.4c<\n", c);     // .뒤에 숫자, warning
	printf("9 >%.c<\n", c);
	printf("10>%0.0c<\n", c);    // warning
	printf("11>%0.c<\n", c);     // warning
	printf("12>%0c<\n", c);      // warning
}
