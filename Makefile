# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =	main.c \
		check_args.c \
		file.c \
		utils.c \
		ft_split.c \
		error.c \
		check.c \

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = pipex
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME}
		@${RM} -r ${OBJ_DIR}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re