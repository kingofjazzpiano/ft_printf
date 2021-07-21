#include "ft_printf.h"

void	ft_putptr(size_t ptr)
{
	int		digit;
	int		i;
	int		array[12];

	if (!ptr)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (ptr)
	{
		digit = ptr % 16;
		if (digit > 9)
			array[i++] = digit - 10 + 'a';
		else
			array[i++] = digit + '0';
		ptr /= 16;
	}
	i--;
	while (i >= 0)
		ft_putchar(array[i--]);
}
