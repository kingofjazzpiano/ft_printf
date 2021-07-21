#include "ft_printf.h"

static int		setup_width_n_precision(const char *s, int i, va_list arg)
{
	while (!(ft_strchr("cspdiouxXfgen%", s[i])))
	{
		if (s[i] == '*')
			g_w = va_arg(arg, int);
		if (s[i] == '.')
		{
			if (s[i + 1] == '*')
			{
				g_p = va_arg(arg, int);
				i++;
			}
			else
				g_p = ft_atoi(s + i + 1);
		}
		g_flags |= (s[i] == 'l') ? IS_L : 0;
		if (s[i] == 'h')
		{
			if (s[i + 1] == 'h')
				g_flags |= IS_HH;
			else if (s[i - 1] != 'h')
				g_flags |= IS_H;
		}
		i++;
	}
	return (i);
}

char			*ft_format(const char *s, va_list arg, size_t i)
{
	g_p = -1;
	g_w = 0;
	g_flags = 0;
	i = setup_width_n_precision(s, i, arg);
	if (!s[i])
		return ((char *)++s);
	else if (ft_strchr("pdiouxXfge", s[i]))
		return (ft_print_nbr_part0((char *)s, i, arg));
	else if (s[i] == 's')
		return (ft_print_str((char *)s, arg));
	else if (s[i] == '%')
		return (ft_print_symbol((char *)s, '%'));
	else if ((s[i] == 'c') && (g_flags & IS_L))
		return (ft_print_symbol((char *)s, va_arg(arg, unsigned int)));
	else if (s[i] == 'c')
		return (ft_print_symbol((char *)s, va_arg(arg, int)));
	else if (s[i] == 'n')
	{
		*va_arg(arg, int*) = g_length;
		while (*s != 'n')
			s++;
	}
	return ((char *)++s);
}
