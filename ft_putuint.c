#include "ft_printf.h"

void	ft_putuint(__uint128_t n)
{
	int		digits[20];
	int		i;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (n)
	{
		digits[i++] = n % 10;
		n /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar('0' + digits[i--]);
}
