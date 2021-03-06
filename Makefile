# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:54:48 by ykolomie          #+#    #+#              #
#    Updated: 2017/09/30 13:02:28 by ykolomie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR =        ./srcs/
OBJ_DIR =        ./obj/
LIBFT_DIR =      ./libft
LIBMATHX_DIR =   ./math_extended
LIBMLX_DIR =     ./minilibx_macos

LIBFT =         libft.a
LIBMATHX =      libmathx.a
LIBMLX =        libmlx.a

SRC_FILES = 			main.c				\
				fdf.c			        \
				read_map_part1.c                \
				read_map_part2.c                \
				viewing_transformations.c	\
				rasterization.c			\
				camera_transformations.c	\
				world_transformations.c		\
				matrix_transformations_part1.c	\
				matrix_transformations_part2.c	\
				matrix_transformations_part3.c	\
				clipping.c                      \
				render.c                        \
				rgb.c                           \
				hsv.c							\
				hooks.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC = -I ./includes -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -I $(LIBMATHX_DIR)

LIBFLAGS = -lft -L $(LIBFT_DIR) -lmlx -L $(LIBMLX_DIR) -L $(LIBMATHX_DIR) -lmathx -lm

FRAMEWORKS = -framework OpenGL -framework AppKit

FLAGS = -Werror -Wextra -Wall

OPT = -O3

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(LIBMATHX_DIR)/$(LIBMATHX) $(LIBMLX_DIR)/$(LIBMLX)
	     $(CC) $(OBJ) $(FLAGS) $(OPT) $(FRAMEWORKS) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@  

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT_DIR)/$(LIBFT):
	make -s -C $(LIBFT_DIR)/

$(LIBMATHX_DIR)/$(LIBMATHX):
	make -s -C $(LIBMATHX_DIR)/
	
$(LIBMLX_DIR)/$(LIBMLX):
	make -s -C $(LIBMLX_DIR)/
	
clean: libclean
	rm -rf $(OBJ)

fclean: clean libfclean
	rm -rf $(NAME)

libclean:
	make clean -C $(LIBFT_DIR)/
	make clean -C $(LIBMATHX_DIR)/
	make clean -C $(LIBMLX_DIR)/

libfclean:
	make fclean -C $(LIBFT_DIR)/
	make fclean -C $(LIBMATHX_DIR)/
	make clean -C $(LIBMLX_DIR)/

re: fclean libfclean all
