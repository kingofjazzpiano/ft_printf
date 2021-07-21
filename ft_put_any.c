#include "ft_printf.h"

static void		put_any_d(va_list arg, char *s)
{
	if ((*s == 'd' || *s == 'i') && (g_flags & IS_L))
		ft_putnbr(va_arg(arg, long long));
	else if ((*s == 'd' || *s == 'i') && (g_flags & IS_H))
		ft_putnbr((short)va_arg(arg, int));
	else if ((*s == 'd' || *s == 'i') && (g_flags & IS_HH))
		ft_putnbr((char)va_arg(arg, int));
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(arg, int));
}

static void		put_any_u(va_list arg, char *s)
{
	if ((*s == 'u') && (g_flags & IS_H))
		ft_putuint((unsigned short)va_arg(arg, unsigned int));
	else if ((*s == 'u') && (g_flags & IS_HH))
		ft_putuint((unsigned char)va_arg(arg, unsigned int));
	else if ((*s == 'u') && (g_flags & IS_L))
		ft_putuint(va_arg(arg, unsigned long long));
	else if (*s == 'u')
		ft_putuint(va_arg(arg, unsigned int));
}

static void		put_any_o(va_list arg, char *s)
{
	if ((*s == 'o') && (g_flags & IS_L))
		ft_putoct(va_arg(arg, unsigned long));
	else if (*s == 'o')
		ft_putoct(va_arg(arg, unsigned int));
}

static void		put_any_x(va_list arg, char *s)
{
	if ((*s == 'x') && (g_flags & IS_L))
		ft_puthex(va_arg(arg, unsigned long), 0);
	else if ((*s == 'x') && (g_flags & IS_HH))
		ft_puthex((unsigned char)va_arg(arg, size_t), 0);
	else if ((*s == 'x') && (g_flags & IS_H))
		ft_puthex((unsigned short)va_arg(arg, size_t), 0);
	else if (*s == 'x')
		ft_puthex(va_arg(arg, unsigned int), 0);
}

void			ft_put_any(va_list arg, char *s)
{
	put_any_d(arg, s);
	put_any_u(arg, s);
	put_any_o(arg, s);
	put_any_x(arg, s);
	if ((*s == 'X') && (g_flags & IS_L))
		ft_puthex(va_arg(arg, unsigned long), 1);
	else if ((*s == 'X') && (g_flags & IS_HH))
		ft_puthex((unsigned char)va_arg(arg, size_t), 1);
	else if ((*s == 'X') && (g_flags & IS_H))
		ft_puthex((unsigned short)va_arg(arg, size_t), 1);
	else if (*s == 'X')
		ft_puthex(va_arg(arg, unsigned int), 1);
	if (*s == 'p')
	{
		ft_putstr("0x");
		if (g_p == -1)
			ft_puthex(va_arg(arg, size_t), 0);
	}
	if (g_flags & ISDOUBLE)
		ft_putreal(va_arg(arg, double));
	g_flags |= PRINTED;
}
