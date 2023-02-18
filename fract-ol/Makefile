# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:59:06 by maruzibo          #+#    #+#              #
#    Updated: 2023/02/14 16:25:36 by maruzibo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name (name of the final executable)

NAME	= fractol

# used complier and flags
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
CF	= $(CC) $(CFLAGS)

#path to minilibx
MLX_PATH	= mlx_linux/
MLX_NAME	= libmlx.a
MLX		= $(MLX_PATH) $(MLX_NAME)

#included folders 
INC		= -I ./headers/\
		  -I ./libft/\
		  -I .mlx_linux/
#sources
SRC_PATH	=	src/
SRC		=	fractol.c \
				initialization.c \
				utils.c \
				events.c \
				render.c \
				color.c \
				parse_args.c \
				help_msg.c \
				fractals/mandelbrot.c \
				fractals/julia.c \
				fractals/burning_ship.c \
				fractals/sierp.c \
				fractals/barns.c\
				color_schemes/color_interpolated.c \
				color_schemes/color_special.c \
				color_schemes/color_striped.c

#create full path to the source files
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Save the object files in obj: 
OBJ_PATH	= objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CF) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractals/
	@mkdir $(OBJ_PATH)coloring/

$(MLX):
	@echo "Wait! I am making MiniLibX."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Now making libft."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling your fractal..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Finally I am done."

bonus: all

clean:
	@echo "Hey I am removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol (it is executable)..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean

