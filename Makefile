NAME		= push_swap

SRCS		= \
push_swap.c push.c swap.c rotate.c rotate_2.c utils.c utils_2.c utils_3.c sort.c \
last_sort.c last_sort_2.c algorithm.c

VPATH			= $(OBJS_DIR) $(FILES) $(INCLUDES) $(LIBFT_INC) $(LIBFT_PATH)

OBJS_DIR		= ./objects
FILES			= ./srcs
LIBFT_PATH		= ./libft
INCLUDES		= ./includes

FLAGS			= -Wall -Wextra -Werror
OPT				= -O3 -flto -Ofast -ffast-math -march=native
LIBFT			= -L libft -lft
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all:				libs $(NAME)

libs:
						@make -C ./libft

$(NAME):			$(OBJS)
						@gcc $(FLAGS) $(LIBFT) $^ -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

$(OBJS_DIR)/%.o:	%.c push_swap.h libft.a
						@mkdir -p $(OBJS_DIR)
						@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

lldb:				$(OBJS)
						@gcc -g $(FLAGS) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

fsanitize:			$(OBJS)
						@gcc -fsanitize=address $(FLAGS) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

clean:
						@rm -f $(OBJS)
						@rm -rf $(OBJS_DIR)
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean

re:					fclean all

.PHONY:				all clean fclean re

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
