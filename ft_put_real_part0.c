#include "ft_printf.h"

void		ft_put_real_part0(long double *f,
							int *exp,
							__uint128_t *all_digits)
{
	if ((g_flags & HASH) && (g_flags & ISZERO) && (g_flags & IS_G))
		g_p -= 1;
	*all_digits = *f * ft_pow10(21);
	*all_digits /= ft_pow10(20 - g_p);
	if ((*f == 0.5 || *f == 1.5 || *f == 2.5 || *f == 3.5 || *f == 4.5
		|| *f == 5.5 || *f == 6.5 || *f == 7.5 || *f == 8.5 || *f == 9.5)
		&& *all_digits % 10 == 5)
	{
		*all_digits /= 10;
		*all_digits += (*all_digits % 2);
	}
	else
	{
		if (*all_digits % 10 >= 5
			&& *f * ft_pow10(g_p + 1) >= (long double)*all_digits)
			*all_digits = *all_digits / 10 + 1;
		else
			*all_digits /= 10;
		if (*exp && *all_digits == 10)
		{
			*exp += 1;
			*all_digits /= 10;
		}
	}
}
