#include "ft_printf.h"

char			*ft_print_str(char *s, va_list argument)
{
	char		*x;

	x = va_arg(argument, char *);
	g_flags |= (*s == '-' || g_w < 0) ? DASH : 0;
	while (*s == '-')
		s++;
	g_w = g_w < 0 ? -g_w : g_w;
	if (g_w)
		g_w -= g_p >= 0 && g_p < (int)ft_strlen(x) ? g_p : ft_strlen(x);
	else
		g_w = g_p >= 0 && g_p < (int)ft_strlen(x) ? ft_atoi(s) - g_p :
											ft_atoi(s) - ft_strlen(x);
	if (g_flags & DASH)
		ft_pre_putstr(x);
	while (g_w > 0 && g_w--)
		ft_putchar(' ');
	while (*s != 's')
		if (*s++ == '.' && !(g_flags & PRINTED))
			ft_pre_putstr(x);
	if (!(g_flags & PRINTED))
		ft_pre_putstr(x);
	return ((char *)++s);
}
