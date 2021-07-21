#include "ft_printf.h"

static	int	ft_counting_digits2(int *digits, __uint128_t all_digits,
								int nbr_of_digits, int precision)
{
	int		i;
	int		j;

	i = 0;
	while (i < precision)
	{
		digits[i++] = all_digits % 10;
		all_digits /= 10;
	}
	i -= 1;
	j = 0;
	if (!(g_flags & HASH))
		while (!digits[j] && j <= i)
			j++;
	if ((precision || (g_flags & HASH)) && (j <= i || i == -1))
		nbr_of_digits += 1;
	else if (g_flags & HASH)
		nbr_of_digits += 1;
	while (i >= j && precision != 0 && precision--)
	{
		nbr_of_digits++;
		i--;
	}
	return (nbr_of_digits);
}

int			ft_counting_digits(__uint128_t integer_part, __uint128_t all_digits)
{
	int		nbr_of_digits;
	int		digits[30];

	nbr_of_digits = 0;
	if (integer_part)
		while (integer_part)
		{
			nbr_of_digits++;
			integer_part /= 10;
		}
	else
		nbr_of_digits = 1;
	return (ft_counting_digits2(digits, all_digits, nbr_of_digits, g_p));
}
