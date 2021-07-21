#include "ft_printf.h"

char	*ft_print_symbol(char *s, unsigned int c)
{
	g_flags |= ((*s == '-' || g_w < 0) && s++) ? DASH : 0;
	while (*s == '0' || *s == '-')
		g_flags |= (*s++ == '0') ? ZERO : 0;
	g_w = g_w < 0 ? -g_w : g_w;
	g_w = g_w ? g_w - 1 : ft_atoi(s) - 1;
	while (*s != '%' && *s != 'c')
		s++;
	if (g_flags & DASH)
		ft_putchar(c);
	g_flags |= (g_flags & DASH) ? PRINTED : 0;
	g_flags &= (g_flags & DASH) ? ~ZERO : g_flags;
	while ((g_flags & ZERO) && (g_w-- > 0))
		ft_putchar('0');
	while (!(g_flags & ZERO) && (g_w-- > 0))
		ft_putchar(' ');
	if (!(g_flags & PRINTED))
		ft_putchar(c);
	return ((char *)++s);
}
