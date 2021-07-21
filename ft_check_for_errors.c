#include "ft_printf.h"

int				ft_check_for_errors(char *s, va_list argument)
{
	size_t		i;
	va_list		tmp_arg;

	if (!s)
		return (0);
	va_copy(tmp_arg, argument);
	i = 0;
	while (s[i])
	{
		if (s[i++] == '%')
		{
			g_flags = 0;
			while (!(ft_strchr("cspdiouxXfgen%", s[i])))
				g_flags |= (s[i++] == 'l') ? IS_L : 0;
			if ((char)va_arg(tmp_arg, unsigned int) < 0 &&
				s[i] == 'c' && (g_flags & IS_L))
			{
				g_flags |= ERROR;
				return (-1);
			}
			return (0);
		}
	}
	return (0);
}
