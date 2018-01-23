# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcooray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 20:58:32 by dcooray           #+#    #+#              #
#    Updated: 2017/01/13 21:58:13 by dcooray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  	read.c \
		event.c \
		color.c \
		error.c \
		expose.c \
		pixel_put.c \
		straight_line.c \
		pixel_put_last.c \
		pixel_put_last_bis.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

PATHFT = ./libft

INCLUDE = -I./includes

LIBFT = -L$(PATHFT) -lft

MLX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: libft.a $(NAME)

libft.a:
	make -C $(PATHFT)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INCLUDE) -c $^

clean:
	/bin/rm -f $(OBJ)
	make -C $(PATHFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATHFT) fclean

re: fclean all
