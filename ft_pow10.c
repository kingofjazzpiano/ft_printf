#include "ft_printf.h"

__uint128_t		ft_pow10(int exp)
{
	__uint128_t result;

	result = 1;
	while (exp-- > 0)
		result *= 10;
	return (result);
}
