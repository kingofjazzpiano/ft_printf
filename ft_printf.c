#include "ft_printf.h"

size_t			g_length;
int				g_flags;
int				g_w;
int				g_p;

int				ft_printf(const char *s, ...)
{
	va_list		argument;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	va_start(argument, s);
	g_length = 0;
	while (s != NULL && *s && !ft_check_for_errors((char*)s, argument))
		if (*s == '%' && s++)
			s = ft_format(s, argument, i);
		else
			ft_putchar(*s++);
	va_end(argument);
	return (g_flags & ERROR) ? -1 : (int)(g_length);
}
