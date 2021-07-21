#include "ft_printf.h"

void	ft_exp_format(long double *f, int *exp)
{
	if (*f >= 1.0)
		while ((int)(*f / 10) && ++(*exp))
			*f /= 10;
	else if (*f < 1.0)
		while (*f < 1.0)
		{
			*f *= 10;
			(*exp)--;
		}
}
