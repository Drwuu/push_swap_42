NAME		= push_swap

SRCS		= \
push_swap.c swap_a.c

VPATH			= $(GNL_PATH) $(INCLUDES) $(LIBFT_PATH) $(SRCS_PATH) $(OBJS_DIR)

FLAGS			= -g -Wall -Wextra -Werror
OPT				= -O3 -flto -Ofast -ffast-math -march=native 
INCLUDES		= ./includes
LIBFT			= -L ./libft -lft
SRCS_PATH			= ./srcs
LIBFT_PATH		= ./libft
GNL_PATH		= ./libft/gnl
OBJS_DIR		= ./objects
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

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

all:				libs $(NAME)

libs:		
						@make -C ./libft

$(NAME):			$(OBJS)
						@gcc $(LIBFT) $^ -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

$(OBJS_DIR)/%.o:	%.c push_swap.h get_next_line.h libft.a
						@gcc $(OPT) -I$(INCLUDES) -I$(LIBFT_PATH)/includes \
						-I$(GNL_PATH) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

linux:				$(OBJS)
						@gcc $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

lldb:				$(OBJS)
						@gcc -g $(FLAGS) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

fsanitize:			$(OBJS)
						@gcc -fsanitize=address $(FLAGS) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

clean:
						@rm -f $(OBJS)
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean 

re:					fclean all

.PHONY:				all clean fclean re libs
