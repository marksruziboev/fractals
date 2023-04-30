# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 11:34:23 by maruzibo          #+#    #+#              #
#    Updated: 2023/04/30 11:19:37 by maruzibo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

# path to Minilibx
MLX	= ./mlx_linux/libmlx.a

# path to Libft
LIBFT	= ./libft/libft.a

# sources 
SRC 	= julia.c create.c fract.c help.c utils.c mandelbrot.c barns.c sierp.c

#objects 
OBJ     = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(MLX) -o $(NAME) -lXext -lX11 -lm


$(LIBFT):
	@make -C libft

$(MLX):
	@make -C mlx_linux

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@make clean -C mlx_linux

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
