CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(MLX_DIR)

MLX_DIR = /usr/include/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

MLX_INCLUDE = -I$(MLX_DIR)
MLX_LINK = $(MLX_LIB) -L/usr/lib -lXext -lX11 -lm

NAME = fractol
SRCS = main.c mandelbrot.c utils.c atof.c fractol_render.c events.c init.c julia.c 
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

