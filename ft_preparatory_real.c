#include "ft_printf.h"

void		ft_preparatory_real(long double *f, int *exp, int *zeros)
{
	*exp = 0;
	*zeros = (g_p > 20) ? g_p - 20 : 0;
	g_p = (g_p > 20) ? 20 : g_p;
	*f = (*f < 0) ? -*f : *f;
	g_p = (!g_p && (g_flags & IS_G)) ? 1 : g_p;
}
