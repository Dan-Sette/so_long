# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 22:01:56 by dalves-s          #+#    #+#              #
#    Updated: 2021/09/15 23:18:45 by dalves-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = 	main.c \
				get_map_struct.c \
				get_next_line.c \
				get_next_line_utils.c \
				map.c \
				movements.c \
				put_image.c \
				player_move.c \
				sides_up_down.c
				
SRC_DIR = ./src
MLX_DIR = ./minilibx-linux/
MLX = ./minilibx-linux/libmlx.a
CFLAGS = -g3 -Wall -Wextra -Werror  #-fsanitize=address
CC = clang
LIBS_FLAGS = -lmlx -Ilmlx -lXext -lX11
OBJECT = $(addprefix $(OBJECT_DIR)/,$(subst .c,.o,$(SRC_FILES)))
OBJECT_DIR = ./objects
LIBFT = libft/libft.a
LIBFT_DIR = ./libft
INCLUDES = ./includes
MAKE_DIR = mkdir -p
NAME = so_long

all:	$(NAME)

$(NAME):	$(MLX) $(OBJECT) $(LIBFT)
		$(CC) $(OBJECT) -L $(MLX_DIR) $(LIBFT) $(LIBS_FLAGS) $(MLX) -o $(NAME)

$(OBJECT_DIR)/%.o:	$(SRC_DIR)/%.c
		$(MAKE_DIR) $(OBJECT_DIR)
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX):
		$(MAKE) -C $(MLX_DIR)

clean:
		rm -fr $(OBJECT_DIR)
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re