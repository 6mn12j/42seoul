
	int main(void)
{
	printf("===========start============\n");
	printf("==========integer===========\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%4.*d|\n", 4, 135) - 16);
	printf("출력 수: %d\n", printf("real printf: |%4.*d|\n", 4, 135) - 16);
	printf("=========unsigned int=======\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%06u|\n", 4294967295) - 16);
	printf("출력 수: %d\n", printf("real printf: |%06u|\n", (unsigned int)4294967295) - 16);
	printf("============char============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%6c%c|\n", 'a', 'b') - 16);
	printf("출력 수: %d\n", printf("real printf: |%6c%c|\n", 'a', 'b') - 16);
	printf("=============str============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%6s|\n", "str") - 16);
	printf("출력 수: %d\n", printf("real printf: |%6s|\n", "str") - 16);
	printf("=============per============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%%|\n") - 16);
	printf("출력 수: %d\n", printf("real printf: |%%|\n") - 16);
	printf("==============x=============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%010x|\n", -1) - 16);
	printf("출력 수: %d\n", printf("real printf: |%010x|\n", -1) - 16);
	printf("==============xl============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%010X|\n", -1) - 16);
	printf("출력 수: %d\n", printf("real printf: |%010X|\n", -1) - 16);
	printf("=============adr============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%17p|\n", "da") - 16);
	printf("출력 수: %d\n", printf("real printf: |%17p|\n", "da") - 16);
	printf("============end=============\n");
	return (0);
}
}
