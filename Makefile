# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =	main.c \
		check_args.c \
		file.c \
		utils.c \
		ft_split.c \
		error.c \
		check.c \
		free.c \

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~ SOURCES BONUS ~~~~~~ */
SRCS_BONUS_DIR = ./srcs_bonus/
SRCS_BONUS =	main_bonus.c \
		check_args_bonus.c \
		file_bonus.c \
		utils_bonus.c \
		ft_split_bonus.c \
		error_bonus.c \
		check_bonus.c \
		free_bonus.c \

OBJS_BONUS = ${addprefix ${SRCS_BONUS_DIR}, ${SRCS_BONUS:.c=.o}}

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

all_bonus:	${NAME}

bonus: $(OBJS_BONUS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED BONUS]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

clean_bonus:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS_BONUS} ${NAME}

fclean_bonus: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS_BONUS} ${NAME}

re_bonus: 	fclean_bonus all_bonus

.PHONY: all clean fclean re bonus all_bonus clean_bonus fclean_bonus re_bonus