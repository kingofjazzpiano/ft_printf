#include "ft_printf.h"

static void		ft_print_nbr_part4(char **s, int *nbr_digits)
{
	while (ft_strchr("0+- #", **s))
	{
		g_flags |= (**s == '+') ? PLUS : 0;
		g_flags |= (**s == '0') ? ZERO : 0;
		g_flags |= (**s == '-') ? DASH : 0;
		g_flags |= (**s == ' ') ? SPACE : 0;
		g_flags |= (**s == '#' && !(g_flags & ISZERO)) ? HASH : 0;
		g_flags |= (**s == '#' && (g_flags & ISDOUBLE)) ? HASH : 0;
		(*s)++;
	}
	*nbr_digits += (g_flags & ISDOUBLE)
	&& (g_p || (g_flags & HASH)) ? g_p + 1 : 0;
	g_flags &= ((g_flags & PLUS) || (g_flags & NEGATIVE))
	&& (g_flags & SPACE) ? ~SPACE : g_flags;
	g_flags &= (g_flags & PLUS) && (g_flags & NEGATIVE) ? ~PLUS : g_flags;
	if (g_w && !(g_flags & IS_G))
		g_w -= (g_p > *nbr_digits) ? g_p : *nbr_digits;
	else if (!g_w && !(g_flags & IS_G))
		g_w = (g_p > *nbr_digits) ? ft_atoi(*s) - g_p
		: ft_atoi(*s) - *nbr_digits;
	else if (!g_w && (g_flags & IS_G))
		g_w = ft_atoi(*s);
	g_w -= ((g_flags & PLUS) || ((g_flags & HASH) &&
	!(g_flags & ISDOUBLE)) || (g_flags & NEGATIVE) || (g_flags & SPACE));
	g_w -= (g_flags & IS_E) ? 4 : 0;
}

static void		ft_print_nbr_part5(char **s)
{
	while (!(ft_strchr("pdiouxXfge", **s)))
		(*s)++;
	g_w -= (g_flags & HASH) && (**s == 'x' || **s == 'X');
	g_w -= (**s == 'p') ? 2 : 0;
	if (g_flags & SPACE)
		ft_putchar(' ');
	if (((g_flags & ZERO) || (g_flags & DASH)) && (g_flags & PLUS))
		ft_putchar('+');
	g_flags &= ((g_flags & ZERO) || (g_flags & DASH))
	&& (g_flags & PLUS) ? ~PLUS : g_flags;
	g_flags &= (g_p >= 0) && (ft_strchr("diouxX", **s)) ? ~ZERO : g_flags;
	if (((g_flags & ZERO) || (g_flags & DASH)) && (g_flags & NEGATIVE))
		ft_putchar('-');
	g_flags &= ((g_flags & ZERO) || (g_flags & DASH))
	&& (g_flags & NEGATIVE) ? ~NEGATIVE : g_flags;
	if ((g_flags & HASH) && (g_flags & DASH) && !(g_flags & ISDOUBLE))
	{
		ft_putchar('0');
		if (**s == 'x')
			ft_putchar('x');
		if (**s == 'X')
			ft_putchar('X');
		g_flags &= ~HASH;
	}
	g_w += !g_p && **s == 'p' ? 1 : 0;
}

static void		ft_print_nbr_part6(char **s, int *nbr_digits, va_list arg)
{
	if (g_flags & DASH)
	{
		while ((*nbr_digits)++ < g_p)
			ft_putchar('0');
		ft_put_any(arg, *s);
		g_flags |= PRINTED;
	}
	if ((g_flags & HASH) && (g_flags & ZERO) && g_p < 0)
	{
		ft_putchar('0');
		if (**s == 'x')
			ft_putchar('x');
		if (**s == 'X')
			ft_putchar('X');
		g_flags &= ~HASH;
	}
	while (g_w > 0 && !(g_flags & IS_G) && g_w--)
		if ((g_flags & ZERO) && (g_p || (g_flags & ISDOUBLE)))
			ft_putchar('0');
		else
			ft_putchar(' ');
}

static void		ft_print_nbr_part7(char **s, int *nbr_digits, va_list arg)
{
	if ((g_flags & HASH) && !(g_flags & ISDOUBLE))
	{
		if ((**s == 'o' && (*nbr_digits - g_p) > -1) || (ft_strchr("xX", **s)))
			ft_putchar('0');
		if (**s == 'x')
			ft_putchar('x');
		if (**s == 'X')
			ft_putchar('X');
	}
	if ((g_flags & NEGATIVE) && !(g_flags & IS_G))
		ft_putchar('-');
	if ((g_flags & PLUS) && !(g_flags & NEGATIVE) && !(g_flags & IS_G))
		ft_putchar('+');
	while ((*nbr_digits)++ < g_p)
		ft_putchar('0');
	if (!(g_flags & PRINTED))
		ft_put_any(arg, *s);
}

char			*ft_print_nbr_part0(char *s, size_t i, va_list arg)
{
	long		prnt_nbr;
	int			nbr_digits;

	ft_print_nbr_part1(s, arg, &prnt_nbr, i);
	if ((!prnt_nbr || !(int)prnt_nbr) && !g_p
	&& !(g_flags & ISDOUBLE) && !(s[i] == 'p' && g_p == 0))
	{
		va_arg(arg, int);
		return (ft_print_space(s, g_w));
	}
	ft_print_nbr_part2(s, i, &prnt_nbr);
	ft_print_nbr_part3(s, i, &prnt_nbr, &nbr_digits);
	ft_print_nbr_part4(&s, &nbr_digits);
	g_flags &= g_p > 0 && !(g_flags & ISDOUBLE) ? ~ZERO : g_flags;
	g_flags &= (g_flags & ZERO) && (g_flags & DASH) ? ~ZERO : g_flags;
	ft_print_nbr_part5(&s);
	ft_print_nbr_part6(&s, &nbr_digits, arg);
	ft_print_nbr_part7(&s, &nbr_digits, arg);
	return ((char *)++s);
}
