#include "ft_printf.h"

void		ft_print_nbr_part3(char *s, size_t i,
							long *prnt_nbr, int *nbr_digits)
{
	g_p = (g_p < 0 && (g_flags & ISDOUBLE)) ? 6 : g_p;
	*prnt_nbr = (g_flags & IS_H) ? (short)*prnt_nbr : *prnt_nbr;
	*prnt_nbr = (g_flags & IS_HH) ? (char)*prnt_nbr : *prnt_nbr;
	*prnt_nbr = ft_strchr("uoxX", s[i]) && (g_flags & IS_H) ?
	(unsigned short)*prnt_nbr : *prnt_nbr;
	*prnt_nbr = ft_strchr("uoxX", s[i]) && (g_flags & IS_HH) ?
	(unsigned char)*prnt_nbr : *prnt_nbr;
	g_flags |= (!*prnt_nbr) && !(g_flags & ISDOUBLE) ? ISZERO : 0;
	if (!(g_flags & IS_H) && !(g_flags & IS_HH) && !(g_flags & IS_L))
		*prnt_nbr = ft_strchr("uoxX", s[i]) ?
		(unsigned int)*prnt_nbr : *prnt_nbr;
	*nbr_digits = 1;
	while (s[i] == 'o' && (*prnt_nbr /= 8))
		(*nbr_digits)++;
	if (s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
		while (*prnt_nbr /= 16)
			(*nbr_digits)++;
	else
		while (*prnt_nbr /= 10)
			(*nbr_digits)++;
}
