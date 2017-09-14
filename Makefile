# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:54:48 by ykolomie          #+#    #+#              #
#    Updated: 2017/04/20 15:27:53 by ykolomie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = ./srcs/

OBJDIR = ./obj/

SRC_FILES = 	main.c						\
				fdf.c						\
				base_structures.c			\
				read_map.c				\
				viewing_transformations.c		\
				rasterization.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRCDIR), $(SRC_FILES))

OBJ = $(addprefix $(OBJDIR), $(OBJ_FILES))

INC = -I ./includes -I $(LIBFTFOLDER) -I $(LMLXFOLDER) -I $(LIBMATHXFOLDER)

LIB = libft.a

LIBFLAGS = -lft -L $(LIBFTFOLDER) -lmlx -L $(LMLXFOLDER) -lm -L $(LIBMATHXFOLDER) -lmathx

LIBFTFOLDER = ./libft/

LIBMATHXFOLDER = ./math_extended/


LMLXFOLDER = ./minilibx_macos
#LMLXFOLDER = ./minilibx

#FRAMEWORKS = -lXext -lX11
FRAMEWORKS = -framework OpenGL -framework AppKit

#RETURN FLAGS PLEASE
#FLAGS = -Werror -Wextra -Wall
FLAGS = -Werror

CC = clang

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTFOLDER)$(LIB)
	$(CC) $(FLAGS) $(FRAMEWORKS) $(OBJ) $(LIBFLAGS) -o $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@  

$(LIBFTFOLDER)$(LIB):
	make -C $(LIBFTFOLDER)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

libclean:
	make clean -C $(LIBFTFOLDER)

libfclean:
	make fclean -C $(LIBFTFOLDER)

re: fclean libfclean all
