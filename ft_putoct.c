#include "ft_printf.h"

void	ft_putoct(unsigned long n)
{
	int		i;
	int		array[30];

	if (!n)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (n)
	{
		array[i++] = n % 8;
		n /= 8;
	}
	i--;
	while (i >= 0)
		ft_putchar(array[i--] + '0');
}
