#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void	print_f(double f)
{
	int	i = 10;

	while (i--)
	{
		f *= 10;
		printf("%lld.", (unsigned long long)f % 10);
	}
}

void	f_render(double f, int prec)
{
	ft_putnbr((int)f);
	ft_putchar('.');
	if (f < 0)
		f = -f;
	while (prec--)
	{
		f *= 10;
		ft_putchar((unsigned long long)f % 10 + '0');
		//printf("%c", f % 10 + '0');
	}
}

int		main(void)
{
	ft_putchar('%');
}
