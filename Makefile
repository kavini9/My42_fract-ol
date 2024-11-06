# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 20:45:47 by wweerasi          #+#    #+#              #
#    Updated: 2024/11/03 07:46:23 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_MLX = ./lib/MLX42
DIR_LIBFT = ./lib/libft
DIR_SRC = ./sources
DIR_SRC_BONUS = ./sources_bonus
DIR_OBJ = $(DIR_SRC)/objects
DIR_OBJ_BONUS = $(DIR_BONUS)/objects_bonus

SOURCES = main.c \
	  arg_validate.c \
	  fractol_guide.c \
	  fractol_init.c \
	  fractol_render.c  \
	  color_generate.c \
	  fractol_event.c \

SOURCES_BONUS = main_bonus.c \
	  arg_validate_bonus.c \
	  fractol_guide_bonus.c \
	  fractol_init_bonus.c \
	  fractol_render_bonus.c  \
	  color_generate_bonus.c \
	  fractol_event_bonus.c \

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))
SRC_BONUS = $(addprefix $(DIR_SRC_BONUS)/,$(SOURCES_BONUS))

OBJECTS = $(addprefix $(DIR_OBJECT)/,$(SOURCES:.c=.o))
OBJECTS_BONUS = $(addprefix $(DIR_OBJ_BONUS)/,$(SOURCES_BONUS:.c=.o))

HEADERS = -I ./include -I $(DIR_MLX)/include -I $(DIR_LIBFT)
HEADERS_BONUS = -I ./include_bonus -I $(DIR_MLX)/include -I $(DIR_LIBFT)

LIBMLX = $(DIR_MLX)/build/libmlx42.a
LIBFT = $(DIR_LIBFT)/libft.a

LIBMLX_FLAGS = $(DIR_MLX)/build/libmlx42.a -ldl -lglfw -lm
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBMLX):
	@if [ ! -d $(DIR_MLX) ]; then \
		cd lib && git clone https://github.com/codam-coding-college/MLX42.git \
		$(DIR_MLX); \
	fi
	@if [ ! -f $(DIR_MLX)/build/libmlx42.a ]; then \
		cmake $(DIR_MLX) -B $(DIR_MLX)/build && make -C $(DIR_MLX)/build -j4; \
	fi


$(LIBFT):
	@make -C $(DIR_LIBFT)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(LIBMLX) $(LIBMLX_FLAGS) $(HEADERS) -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

bonus: $(LIBFT) $(LIBMLX) $(OBJECTS_BONUS)
	@$(CC) $(OBJECTS_BONUS) $(LIBFT_FLAGS) $(LIBMLX) $(LIBMLX_FLAGS) $(HEADERS_BONUS) -o $(NAME)_bonus

$(DIR_OBJ_BONUS)/%.o: $(DIR_BONUS)/%.c | $(DIR_OBJ_BONUS)
	@$(CC) $(CFLAGS) $(HEADERS_BONUS) -c $< -o $@

$(DIR_OBJ_BONUS):
	@mkdir -p $(DIR_OBJ_BONUS)

clean:
	@$(RM) $(DIR_OBJ)
	@$(RM) $(DIR_OBJ_BONUS)
	@$(RM) $(DIR_MLX)/build
	@make -C $(DIR_LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME)_bonus
	@$(RM) $(DIR_MLX)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re
