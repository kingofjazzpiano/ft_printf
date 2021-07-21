#include "ft_printf.h"

void		ft_pre_putstr(const char *s)
{
	if (!s)
	{
		ft_pre_putstr("(null)");
		return ;
	}
	if (g_p < 0)
		while (*s)
			ft_putchar(*s++);
	while (*s && g_p > 0)
	{
		ft_putchar(*s++);
		g_p--;
	}
	g_flags |= PRINTED;
}
