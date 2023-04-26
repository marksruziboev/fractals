# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelasam <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:26:08 by eelasam           #+#    #+#              #
#    Updated: 2023/03/21 18:39:50 by eelasam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRCS = mandelbrot.c\
julia.c\
burning_ship.c\
main.c\
utils.c\
error_exit.c\

OBJS = $(SRCS:.c=.o)
MLX = ./mlx_linux/libmlx.a

all : $(NAME)

$(NAME) : $(OBJS) 
		make -C mlx_linux
		cc $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) -lXext -lX11 -lm
		

clean :
		@rm -rf $(OBJS)
		make clean -C mlx_linux

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
