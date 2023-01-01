SRC = ft_printf.c \
		ft_strlen.c \
		ft_is_type.c \
		ft_search_params.c \
		ft_putchar_len.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_convert.c \
		ft_convert_ptr.c \
		ft_putnbr_unsigned.c \
		ft_putnbr.c \
		ft_convert_nbr.c \
		ft_convert_str.c \
		ft_convert_hexa.c \


OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Werror -Wall

NAME = libftprintf.a

CC = cc

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
