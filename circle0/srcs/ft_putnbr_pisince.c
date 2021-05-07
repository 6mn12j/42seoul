void	print_putchar(char c)
{
	write(1, &c, 1);
}

void	int_to_char(int nb)
{
	int	fin;

	fin = nb % 10;
	if (nb == 0)
		return ;
	nb = nb / 10;
	int_to_char(nb);
	print_putchar(fin + '0');
}

void	ft_putnbr(int nb)
{
	int fin;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	fin = nb % 10;
	int_to_char(nb / 10);
	print_putchar(fin + '0');
}
