# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 03:51:23 by ahamouda          #+#    #+#              #
#    Updated: 2016/03/31 08:04:36 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

COMPILER	= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I./includes
LIBS		= -L./libs -lm -lftprintf -lcolor -lmlx -framework OpenGL -framework AppKit
MLX_DIR		= minilibx_macos

TMP_C		=\
			wolf3d_init.c\
			wolf3d_start.c\
			wolf3d_exit.c\
			wolf3d_map_load.c\
			wolf3d_map_del.c\
			wolf3d_map_draw.c\
			wolf3d_map_is_wall.c\
			wolf3d_player_init.c\
			wolf3d_player_draw.c\
			wolf3d_player_move.c\
			wolf3d_ray_draw.c\
			wolf3d_render.c\
			img_putpixel.c\
			img_putline.c\
			img_fill.c\
			img_clear.c\
			event_key.c\
			hook_loop.c\
			hook_expose.c\
			vec_rotate_2d.c\
			pnt_2d_new.c\
			pnt_2d_del.c\
			player_new.c\
			player_del.c\
			textures_load.c\
			check_full_line.c\
			assign.c\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_H		=\
			wolf3d.h\
			ft_printf.h\
			mlx.h

SRC_H		= $(TMP_H:%=includes/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all: $(NAME)

$(NAME): objects libs/libftprintf.a libs/libcolor.a libs/libmlx.a $(SRC_O) $(SRC_H)
	@echo "Creating wolf3d... \c"
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(SRC_O) $(LIBS)
	@echo "[ok]"

objects: 
	@echo "Creating the folder objects... \c"
	@mkdir objects
	@echo "[ok]"

libs/libftprintf.a:
	@echo "Making libftprintf... \c"
	@make -sC libs/libftprintf
	@mv libs/libftprintf/libftprintf.a libs
	@make -sC libs/libftprintf/ fclean
	@echo "[ok]"

libs/libcolor.a:
	@echo "Making libcolor... \c"
	@make -sC libs/libcolor > /dev/null
	@mv libs/libcolor/libcolor.a libs
	@make -sC libs/libcolor fclean /dev/null
	@echo "[ok]"

libs/libmlx.a:
	@echo "Making libmlx... \c"
	@make -s -C libs/$(MLX_DIR)/ > /dev/null
	@mv libs/$(MLX_DIR)/libmlx.a libs
	@make -s -C libs/$(MLX_DIR)/ clean > /dev/null
	@echo "[ok]"

objects/%.o	: srcs/%.c
	@echo "Compiling $<... \c"
	@$(COMPILER) $(CFLAGS) -c $<
	@mv $(notdir $@) objects
	@echo "[ok]"

clean:
	@echo "Removing objects... \c"
	@rm -rf objects
	@echo "[ok]"

fclean: clean
	@echo "Removing all compiled files... \c"
	@rm -rf $(NAME)
	@rm -rf libs/libftprintf.a
	@rm -rf libs/libcolor.a
	@rm -rf libs/libmlx.a
	@echo "[ok]"

re: fclean all

.PHONY: re fclean clean all
