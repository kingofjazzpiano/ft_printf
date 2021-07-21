#include "ft_printf.h"

static void		f_greater_than_10(long double *f, int *exp)
{
	while ((int)(*f / 10) && ++(*exp))
		*f /= 10;
	g_w -= (*exp >= g_p) ? 4 : 0;
	if ((*exp + 1) == g_p)
	{
		*f *= ft_pow10(*exp);
		*exp = 0;
		g_p = 0;
	}
	else if ((*exp + 1) > g_p)
		g_p -= 1;
	else if ((*exp + 1) < g_p)
	{
		*f *= ft_pow10(*exp);
		g_p -= *exp + 1;
		*exp = 0;
	}
}

static void		f_between_1_n_10(long double *f,
								int *digits,
								__uint128_t *all_digits)
{
	digits[31] = 1;
	*all_digits = (int)*f;
	while (*all_digits /= 10)
		digits[31]++;
	g_p -= digits[31];
}

static void		f_less_than_1_p_greater_than_1(long double *f,
											__uint128_t *all_digits)
{
	*all_digits = 0;
	while (!(int)*f)
	{
		(*all_digits)++;
		*f *= 10;
	}
	*f /= ft_pow10(*all_digits);
	g_p += *all_digits - 1;
}

static void		f_less_than_1_p_equal_1(long double *f)
{
	g_p = 0;
	while (!(int)*f)
	{
		g_p++;
		*f *= 10;
	}
	*f /= ft_pow10(g_p);
}

void			ft_def_exp_width_n_prec(long double *f,
										int *exp,
										__uint128_t *all_digits,
										int *digits)
{
	if (*f >= 10.0)
		f_greater_than_10(f, exp);
	else if (*f >= 1.0)
		f_between_1_n_10(f, digits, all_digits);
	else if (g_p > 1 && *f * ft_pow10(4) >= 1.0)
		f_less_than_1_p_greater_than_1(f, all_digits);
	else if (g_p == 1 && *f * ft_pow10(4) >= 1.0)
		f_less_than_1_p_equal_1(f);
	else if (*f < 0.0001)
	{
		g_w -= 4;
		*exp = 5;
		while (!(int)(*f * ft_pow10(*exp)))
			(*exp)++;
		*f *= ft_pow10(*exp);
		*exp = -(*exp);
		g_p -= 1;
	}
}
