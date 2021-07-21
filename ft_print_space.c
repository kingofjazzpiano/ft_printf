#include "ft_printf.h"

char	*ft_print_space(char *s, int w)
{
	while (*s == '-' || *s == '+' || *s == '#' || *s == ' ' || *s == '0')
	{
		g_flags |= (*s == ' ') ? SPACE : 0;
		g_flags |= (*s == '+') ? PLUS : 0;
		g_flags |= (*s++ == '-') ? DASH : 0;
	}
	w = w ? w - ((g_flags & PLUS) >> 6) : ft_atoi(s) - ((g_flags & PLUS) >> 6);
	if ((g_flags & DASH) && (g_flags & PLUS))
		ft_putchar('+');
	g_flags &= (g_flags & DASH) && (g_flags & PLUS) ? ~PLUS : g_flags;
	if (g_flags & SPACE)
		ft_putchar(' ');
	while (w-- > 0)
		ft_putchar(' ');
	if (g_flags & PLUS)
		ft_putchar('+');
	while (!(ft_strchr("pdiouxX", *s)))
		s++;
	return ((char *)++s);
}
