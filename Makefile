# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdijkman <jdijkman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/08 14:05:14 by jdijkman      #+#    #+#                  #
#    Updated: 2025/02/11 14:18:04 by jdijkman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC := cc
CFLAGS := -Wall -Werror -Wextra -O3 -g -I $(LIBFT_PATH)includes
LIBMLX := ./MLX42

SRCS := ./src/main.c \
        ./src/draw.c \
        ./src/map_validation.c \
        ./src/cleanup.c \
        ./src/event_handler.c \
        ./src/event_handler_utils.c \
        ./src/init_structs.c \
        ./src/raycasting.c \
        ./src/raycasting_utils.c \
        ./src/parsing.c \
        ./src/parsing_map.c \
        ./src/minimap.c 

LIBFT_PATH := libft/
LIBFT_NAME := libft.a
LIBFT_FLAGS := -L$(LIBFT_PATH) -lft
LIBFT := $(LIBFT_PATH)$(LIBFT_NAME)

MLX_PATH := MLX42/build/
MLX_NAME := libmlx42.a
HEADERS := -I ./include -I $(LIBMLX)/include
MLX_FLAGS := -L$(MLX_PATH) -lmlx42 -ldl -lglfw -pthread -lm 
MLX := $(MLX_PATH)$(MLX_NAME)

BIN_DIR := bin

OBJS := $(SRCS:./src/%.c=$(BIN_DIR)/%.o)

all: $(BIN_DIR) $(MLX_PATH) $(NAME)

$(BIN_DIR)/%.o: ./src/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(MLX_PATH):
	@mkdir -p $(MLX_PATH)
	@cmake $(LIBMLX) -B $(MLX_PATH) && make -C $(MLX_PATH) -j4

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) all
	@$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BIN_DIR)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
