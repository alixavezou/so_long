# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:35:05 by aavezou           #+#    #+#              #
#    Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#PROGRAM NAME
NAME = libft.a

#SOURCES AND OBJECTS
SRC_NAME =	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line_utils.c \
			get_next_line.c \
			printf_putchar.c \
			printf_putcharcount.c \
			printf_putnbr.c \
			printf_putstrcount.c \
			printf_countnb.c \
			printf_checktype.c \
			printf_libftprintf.c \
			printf_printandcount.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -I inc

all: $(NAME)

$(NAME):$(OBJ)
	@ ar rc  $(NAME) $(OBJ)
	@ ranlib $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ_PATH)

fclean: clean
	@ rm -f $(NAME)

norm:
	@ norminette src inc

re: fclean  all

.PHONY: all clean fclean norm re
