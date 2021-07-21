#include "ft_printf.h"

void	ft_puthex(size_t ptr, int is_upper)
{
	int				digit;
	int				i;
	int				array[20];
	char			letter;

	if (!ptr)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	letter = (is_upper) ? 'A' : 'a';
	while (ptr)
	{
		digit = ptr % 16;
		if (digit > 9)
			array[i++] = digit - 10 + letter;
		else
			array[i++] = digit + '0';
		ptr /= 16;
	}
	i--;
	while (i >= 0)
		ft_putchar(array[i--]);
}
