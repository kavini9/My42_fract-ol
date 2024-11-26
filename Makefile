# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 20:45:47 by wweerasi          #+#    #+#              #
#    Updated: 2024/11/26 19:23:04 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_MLX		= ./lib/MLX42
DIR_LIBFT	= ./lib/libft
DIR_SRC		= ./src
DIR_SRC_BONUS	= ./src_bonus
DIR_OBJ		= $(DIR_SRC)/objects
DIR_OBJ_BONUS	= $(DIR_SRC_BONUS)/objects_bonus
DIR_INC		= ./includes
HEADERS		= $(DIR_INC)/fractol.h
HEADERS_BONUS	= $(DIR_INC)/fractol_bonus.h

SOURCES = main.c \
	  arg_validate.c \
	  error_help.c \
	  fractol_init.c \
	  fractol_event.c \
	  fractol_render.c  \
	  color_generate.c \

SOURCES_BONUS = main_bonus.c \
	  arg_validate_bonus.c \
	  error_help_bonus.c \
	  fractol_init_bonus.c \
	  fractol_event_bonus.c \
	  fractol_render_bonus.c  \
	  color_generate_bonus.c \

OBJECTS		= $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
OBJECTS_BONUS 	= $(addprefix $(DIR_OBJ_BONUS)/,$(SOURCES_BONUS:.c=.o))

LIBMLX		= $(DIR_MLX)/build/libmlx42.a

LIBMLX_FLAGS	= $(LIBMLX) -ldl -lglfw -lm
LIBFT_FLAGS	= -L $(DIR_LIBFT) -lft

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -rf

all: libft $(LIBMLX) $(NAME)
bonus: libft $(LIBMLX) .bonus

libft:
	@make -C $(DIR_LIBFT)

$(LIBMLX):
	@if [ ! -d $(DIR_MLX) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git \
		$(DIR_MLX); \
	fi
	@if [ ! -f $(DIR_MLX)/build/libmlx42.a ]; then \
		cmake $(DIR_MLX) -B $(DIR_MLX)/build && make -C $(DIR_MLX)/build -j4; \
	fi

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $@

.bonus: $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $(NAME)_bonus
	@touch .bonus

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS) | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@

$(DIR_OBJ_BONUS)/%.o: $(DIR_SRC_BONUS)/%.c $(HEADERS_BONUS) | $(DIR_OBJ_BONUS)
	@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ_BONUS):
	@mkdir -p $(DIR_OBJ_BONUS)

clean:
	@$(RM) $(DIR_OBJ) 
	@$(RM) $(DIR_OBJ_BONUS)
	@$(RM) $(DIR_MLX)/build
	@make -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) .bonus
	@$(RM) $(NAME) 
	@$(RM) $(NAME)_bonus
	@$(RM) $(DIR_MLX)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all bonus libft clean fclean re
