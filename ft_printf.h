#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define BIT_0 1
# define BIT_1 2
# define BIT_2 4
# define BIT_3 8
# define BIT_4 16
# define BIT_5 32
# define BIT_6 64
# define BIT_7 128
# define BIT_8 256
# define BIT_9 512
# define BIT_10 1024
# define BIT_11 2048
# define BIT_12 4096
# define BIT_13 8192
# define BIT_14 16384

enum	e_flags
{
	ISZERO = BIT_0,
	ZERO = BIT_1,
	DASH = BIT_2,
	HASH = BIT_3,
	SPACE = BIT_4,
	PRINTED = BIT_5,
	PLUS = BIT_6,
	NEGATIVE = BIT_7,
	ISDOUBLE = BIT_8,
	IS_G = BIT_9,
	IS_E = BIT_10,
	IS_L = BIT_11,
	IS_H = BIT_12,
	IS_HH = BIT_13,
	ERROR = BIT_14
};

union
{
	double			real;
	long			long_int;
	unsigned char	bytes[4];
} type;

extern int			g_flags;
extern size_t		g_length;
extern int			g_w;
extern int			g_p;

int					ft_printf(const char *s, ...);
void				ft_put_any(va_list arg, char *s);
void				ft_print_nbr_part3(char *s, size_t i,
							long *prnt_nbr, int *nbr_digits);
void				ft_print_nbr_part2(char *s, size_t i,
									long *prnt_nbr);
void				ft_print_nbr_part1(char *s, va_list arg,
								long *prnt_nbr, size_t i);
void				ft_put_real_part0(long double *f,
								int *exp,
								__uint128_t *all_digits);
void				ft_preparatory_real(long double *f, int *exp, int *zeros);
void				ft_def_exp_width_n_prec(long double *f,
											int *exp,
											__uint128_t *all_digits,
											int *digits);
void				ft_exp_format(long double *f, int *exp);
__uint128_t			ft_pow10(int exp);
void				put_uint128(__uint128_t n);
char				*ft_print_nbr_part0(char *s, size_t i, va_list argument);
char				*ft_format(const char *s, va_list arg, size_t i);
char				*ft_print_space(char *s, int width);
char				*ft_print_str(char *s, va_list argument);
char				*ft_print_symbol(char *s, unsigned int c);
int					ft_check_for_errors(char *s, va_list argument);
int					ft_counting_digits(__uint128_t integer_part,
										__uint128_t all_digits);
void				ft_putbyte(unsigned char byte);
void				ft_putchar(int c);
void				ft_putstr(const char *s);
void				ft_pre_putstr(const char *s);
void				ft_putnbr(__int128_t n);
void				ft_putuint(__uint128_t n);
void				ft_puthex(size_t ptr, int is_upper);
void				ft_putoct(unsigned long n);
void				ft_putreal(long double f);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);

#endif
