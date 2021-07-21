#include "ft_printf.h"

void	put_uint128(__uint128_t n)
{
	if (!n)
		return ;
	put_uint128(n / 10);
	ft_putchar('0' + n % 10);
}
