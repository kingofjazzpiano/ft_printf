#include "ft_printf.h"

#define INT64_MAX 9223372036854775807LL

int		ft_atoi(const char *str)
{
	unsigned long long	result;
	long long			sign;

	while (*str && (*str == ' ' || *str == '\n' ||
	*str == '\t' || *str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str && (*str >= '0' && *str <= '9') && result <= INT64_MAX)
		result = result * 10 + (*str++ - '0');
	if (result > INT64_MAX && sign == 1)
		return (-1);
	if (result > INT64_MAX && sign == -1)
		return (0);
	return ((int)(result * sign));
}
