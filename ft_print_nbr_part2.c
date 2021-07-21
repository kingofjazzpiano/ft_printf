#include "ft_printf.h"

void		ft_print_nbr_part2(char *s, size_t i,
							long *prnt_nbr)
{
	if (!(g_flags & IS_L) && !(g_flags & IS_H) && !(g_flags & IS_HH))
		g_flags |= (s[i] == 'd' || s[i] == 'i')
		&& ((int)*prnt_nbr < 0) ? NEGATIVE : 0;
	else if (g_flags & IS_L)
		g_flags |= (s[i] == 'd' || s[i] == 'i')
		&& (*prnt_nbr < 0) ? NEGATIVE : 0;
	else if (g_flags & IS_H)
		g_flags |= (s[i] == 'd' || s[i] == 'i')
		&& ((short)*prnt_nbr < 0) ? NEGATIVE : 0;
	else if (g_flags & IS_HH)
		g_flags |= (s[i] == 'd' || s[i] == 'i')
		&& ((char)*prnt_nbr < 0) ? NEGATIVE : 0;
	if ((s[i] == 'd' || s[i] == 'i') && !(g_flags & IS_L))
		*prnt_nbr = (int)*prnt_nbr;
	else if (s[i] == 'p' || s[i] == 'o'
		|| s[i] == 'x' || s[i] == 'X')
		*prnt_nbr = (size_t)*prnt_nbr;
}
