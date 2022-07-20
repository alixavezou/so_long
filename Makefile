NAME = so_long

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lminilibx -lm -lmlx -lXext -lX11

PRINTF_PATH = ft_printf

PRINTF = libftprintf.a

FT_PRINTF = ft_printf/libftprintf.a

MINILIBX_PATH = minilibx

FT_MINILIBX = minilibx/libmlx_Linux.a

MINILIBX = libmlx_Linux.a

C_FILES = srcs/recupmap.c \
			srcs/check_error.c \
			srcs/main.c \
			srcs/walls.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${NAME} : ${O_FILES} ${PRINTF} ${MINILIBX}
	@${CC} ${O_FILES} -Imlx -Iminilibx ${FT_PRINTF} ${FT_MINILIBX} ${MLXFLAGS} -o ${NAME}

${PRINTF} :
	@(cd ${PRINTF_PATH} && ${MAKE})
	@cp ${PRINTF_PATH}/${PRINTF} .

${MINILIBX} :
	@(cd ${MINILIBX_PATH} && ${MAKE}) 2>/dev/null
	@cp ${MINILIBX_PATH}/${MINILIBX} .

clean:
	@${RM} ${O_FILES} ${O_FILES_BONUS}

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS} ${PRINTF} ${MINILIBX}
	@cd ${PRINTF_PATH} && ${MAKE} $@
	@cd ${MINILIBX_PATH} && ${MAKE} $<
	@rm -rf ${FT_MINILIBX}
	@rm -rf ./minilibx/libmlx.a

re: fclean all

.PHONY: all clean fclean re
