
#SELL COLORS
LRED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
LBLUE = \033[34;1m
PINK = \033[35m
LCYAN = \033[36m
END = \033[0m

#PROGRAM NAME
NAME = so_long

#SOURCES AND OBJECTS
SRC_NAME =	recupmap.c \
			check_error.c \
			insidemap.c \
			walls_errors.c \
			check_map_items.c \
			check_map_items2.c \
			initialize_values.c \
			player_moves.c \
			player_position.c \
			so_long.c \
			mlx_to_image.c \
			mlx_to_image2.c \
			srcs_utils.c \
			handle_exit.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -I inc -I ./mlx

#LIBRARY
LIBFT  = -L./libft -lft
MLX = -L./mlx -lmlx -Ofast -framework OpenGL -framework AppKit -L./mlx/libmlx.dylib

all: $(NAME)

$(NAME):$(OBJ)
		@ make -C libft/
		@ make -C mlx/
		@ $(CC) $(FLAGS) $(LIBFT) $(MLX) $^ -o $@
		@ echo "$(GREEN)Compilation done : so_long is ready to be used$(END)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@ mkdir -p $(OBJ_PATH)
		@ $(CC) $(FLAGS) -o $@ -c $<

so_long_only:$(OBJ)
		@ $(CC) $(FLAGS) -g $(LIBFT) $(MLX) $^ -o $(NAME)
		@ echo "$(GREEN)Compilation done : so_long is ready to be used$(END)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@ mkdir -p $(OBJ_PATH)
		@ $(CC) $(FLAGS) -o $@ -c $<

clean:
		@ make -C libft/ clean
		@ make -C mlx/ clean
		@ rm -vf $(OBJ)
		@ rm -rfv $(OBJ_PATH)
		@ echo "$(PINK)Cleaning is done!$(END)"

fclean: clean
		@ rm -vf $(NAME)
		@ make -C libft/ fclean
		@ make -C mlx/ fclean
		@ echo "$(PINK)FCleaning is done!$(END)"

norm:
		@ echo "$(LBLUE)Norminette...$(END)"
		@ norminette src inc

re: 	fclean all

.PHONY: fclean all clean norm re so_long_only
