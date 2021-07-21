#include "ft_printf.h"

void		ft_print_nbr_part1(char *s, va_list arg,
							long *prnt_nbr, size_t i)
{
	va_list		tmp_arg;

	va_copy(tmp_arg, arg);
	g_flags |= (g_w < 0) ? DASH : 0;
	g_w = (g_w < 0) ? -g_w : g_w;
	if (s[i] == 'f' || s[i] == 'g' || s[i] == 'e')
	{
		g_flags |= ISDOUBLE;
		g_flags |= s[i] == 'g' ? IS_G : 0;
		g_flags |= s[i] == 'e' ? IS_E : 0;
		type.real = va_arg(tmp_arg, double);
		g_flags |= (type.long_int >> 63) ? NEGATIVE : 0;
		*prnt_nbr = (int)type.real;
		g_flags |= !type.real ? ISZERO : 0;
	}
	else if (s[i] == 'u' && (g_flags & IS_L))
		*prnt_nbr = va_arg(tmp_arg, unsigned long);
	else
		*prnt_nbr = va_arg(tmp_arg, long long);
}
