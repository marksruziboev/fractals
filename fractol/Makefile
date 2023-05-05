# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:26:08 by eelasam           #+#    #+#              #
#    Updated: 2023/04/29 16:33:13 by maruzibo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#CFLAGS = -Wall -Werror -Wextra

SRCS = example.c#mandelbrot.c julia.c burning_ship.c main.c utils.c error_exit.c\
	

OBJS = $(SRCS:.c=.o)
MLX = ./mlx_linux/libmlx.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX)
		make -C mlx_linux
		cc  $(OBJS) $(MLX) -o $(NAME) -lXext -lX11 -lm
$(MLX):
	make -C mlx_linux
		

clean :
		@rm -rf $(OBJS)
		make clean -C mlx_linux

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
