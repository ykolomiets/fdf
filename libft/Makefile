# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 20:24:37 by ykolomie          #+#    #+#              #
#    Updated: 2017/09/30 10:59:49 by ykolomie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_FILES =	ft_memset.c		    \
		ft_bzero.c		        \
		ft_memcpy.c		        \
		ft_memmove.c	        \
		ft_memchr.c		        \
		ft_memcmp.c		        \
		ft_memccpy.c	        \
		ft_strlen.c		        \
		ft_strdup.c		        \
		ft_strcpy.c		        \
		ft_strncpy.c	        \
		ft_strcat.c		        \
		ft_strlcat.c	        \
		ft_strchr.c		        \
		ft_strrchr.c	        \
		ft_strstr.c		        \
		ft_strnstr.c	        \
		ft_strcmp.c		        \
		ft_strncmp.c	        \
		ft_atoi.c		        \
		ft_isalpha.c	        \
		ft_isdigit.c	        \
		ft_isalnum.c	        \
		ft_isascii.c	        \
		ft_isprint.c	        \
		ft_toupper.c	        \
		ft_tolower.c	        \
		ft_memalloc.c	        \
		ft_memdel.c		        \
		ft_strnew.c		        \
		ft_strdel.c		        \
		ft_strclr.c		        \
		ft_striter.c	        \
		ft_striteri.c	        \
		ft_strmap.c		        \
		ft_strmapi.c	        \
		ft_strequ.c		        \
		ft_strnequ.c	        \
		ft_strsub.c		        \
		ft_strjoin.c	        \
		ft_strtrim.c	        \
		ft_strsplit.c	        \
		ft_itoa.c		        \
		ft_putchar.c	        \
		ft_putstr.c		        \
		ft_putendl.c	        \
		ft_putnbr.c		        \
		ft_putchar_fd.c	        \
		ft_putstr_fd.c	        \
		ft_putendl_fd.c	        \
		ft_putnbr_fd.c	        \
		ft_lstnew.c		        \
		ft_lstdelone.c	        \
		ft_lstdel.c		        \
		ft_lstadd.c		        \
		ft_lstiter.c	        \
		ft_lstmap.c		        \
		ft_strncat.c	        \
		ft_free_table.c         \
		ft_strupcase.c	        \
		ft_strlowcase.c	        \
		ft_atoi_base.c	        \
		ft_count_word.c         \
		ft_table_size.c         \
		ft_malloc_2d_array.c    \
		ft_free_2d_array.c      \
		get_next_line.c	        \
		read.c	

OBJDIR = ./obj/

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRCDIR), $(SRC_FILES))

OBJ = $(addprefix $(OBJDIR), $(OBJ_FILES))

CC = clang

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		   ar rcs $(NAME) $(OBJ)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: clean all
