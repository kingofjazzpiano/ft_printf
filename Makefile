NAME = libftprintf.a

HEADER = ft_printf.h

SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_pre_putstr.c\
		ft_putnbr.c ft_putoct.c ft_putuint.c ft_puthex.c\
		ft_atoi.c ft_strchr.c ft_strlen.c ft_putreal.c\
		ft_counting_digits.c ft_check_for_errors.c	ft_print_symbol.c\
		ft_print_nbr_part0.c ft_print_str.c ft_print_space.c\
		ft_format.c put_uint128.c ft_pow10.c ft_exp_format.c\
		ft_def_exp_width_n_prec.c ft_preparatory_real.c\
		ft_put_real_part0.c ft_print_nbr_part1.c ft_print_nbr_part2.c\
		ft_print_nbr_part3.c ft_put_any.c

OBJ = $(patsubst %c, %o, $(SRC))

FLAG = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	clang $(FLAG) -c $< -o $@

bonus: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
