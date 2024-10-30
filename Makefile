# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 20:45:47 by wweerasi          #+#    #+#              #
#    Updated: 2024/10/30 21:25:45 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_MLX = ./lib/MLX42
DIR_LIBFT = ./lib/libft
DIR_SRC = ./sources
DIR_BONUS = ./sources_bonus
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
SRC_BONUS = $(addprefix $(DIR_BONUS)/,$(SOURCES_BONUS))

