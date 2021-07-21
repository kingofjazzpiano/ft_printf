#include "ft_printf.h"

static void		put_real_part1(long double *f,
							int *exp,
							__uint128_t *all_digits,
							__uint128_t *integer_part)
{
	*integer_part = (__uint128_t)(*all_digits / ft_pow10(g_p));
	if (*integer_part == 10 && ((*exp || g_p < 2) || (g_flags & IS_E))
		&& ((g_flags & IS_G) || (g_flags & IS_E)))
	{
		*integer_part = 1;
		(*exp)++;
		*f /= 10;
	}
	if (g_flags & IS_G)
		g_w -= ft_counting_digits(*integer_part, *all_digits);
	if ((g_flags & IS_G) && !(g_flags & DASH))
		while (g_w > 0 && g_w--)
		{
			if (g_flags & ZERO)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	if ((g_flags & NEGATIVE) && (g_flags & IS_G))
		ft_putchar('-');
	if ((g_flags & PLUS) && (g_flags & IS_G))
		ft_putchar('+');
}

static void		put_real_part2(int *digits,
								__uint128_t *all_digits,
								__uint128_t *integer_part)
{
	if (*integer_part)
		put_uint128(*integer_part);
	else
		ft_putchar('0');
	while (*integer_part)
		*integer_part /= 10;
	digits[30] = 0;
	while (digits[30] < g_p)
	{
		digits[digits[30]++] = *all_digits % 10;
		*all_digits /= 10;
	}
	digits[30]--;
	digits[31] = 0;
	if (g_flags & IS_G)
		while (!digits[digits[31]] && digits[31] <= digits[30]
		&& !(g_flags & HASH))
			digits[31]++;
	if ((g_p || (g_flags & HASH)) && (digits[31] <= digits[30]
		|| digits[30] == -1))
		ft_putchar('.');
	else if ((g_flags & HASH) && (g_flags & IS_G))
		ft_putchar('.');
}

static void		put_real_part3(int *zeros, int *digits)
{
	while (digits[30] >= digits[31] && g_p != 0 && g_p--)
		ft_putchar('0' + digits[digits[30]--]);
	while (*zeros--)
		ft_putchar('0');
	if (g_flags & IS_G)
		while (g_w > 0 && g_w--)
		{
			if (g_flags & ZERO)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
}

static void		put_real_part4(int *exp, int *digits)
{
	if ((g_flags & IS_G) && *exp)
	{
		digits[31] = g_length;
		g_length = digits[31] + ft_printf("e%+03d", *exp);
	}
	if (g_flags & IS_E)
	{
		digits[31] = g_length;
		g_length = digits[31] + ft_printf("e%+03d", *exp);
	}
}

void			ft_putreal(long double f)
{
	int			digits[32];
	__uint128_t	all_digits;
	__uint128_t	integer_part;
	int			zeros;
	int			exp;

	ft_preparatory_real(&f, &exp, &zeros);
	if ((g_flags & IS_E) && !(g_flags & ISZERO))
		ft_exp_format(&f, &exp);
	if ((g_flags & IS_G) && !(g_flags & ISZERO))
		ft_def_exp_width_n_prec(&f, &exp, &all_digits, digits);
	ft_put_real_part0(&f, &exp, &all_digits);
	put_real_part1(&f, &exp, &all_digits, &integer_part);
	put_real_part2(digits, &all_digits, &integer_part);
	put_real_part3(&zeros, digits);
	put_real_part4(&exp, digits);
}
