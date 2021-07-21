#include "ft_printf.h"

size_t		ft_strlen(const char *s)
{
	size_t length;

	if (!s)
		return (6);
	length = 0;
	while (*s++)
		length++;
	return (length);
}
