# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 20:24:18 by dtuiasos          #+#    #+#              #
#    Updated: 2017/10/09 23:24:14 by dtuiasos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC = add_node \
		bresenham \
		build_grid \
		cohen_sutherland \
		color_inc \
		compute_code \
		draw_lines \
		expose_hook \
		first_step \
		free_dbl \
		init_c \
		init_env \
		init_z \
		key_press_hook \
		key_release_hook \
		loop_hook \
		mouse_motion_hook \
		mouse_press_hook \
		mouse_release_hook \
		parse_data \
		pulse_pastel \
		reset_xyz \
		rotate_obj \
		rotate_orbit \
		rotate_x \
		rotate_y \
		rotate_z \
		scale_center \
		start_draw \
		threader \
		translate_xyz \
		main \

LIB_H = -I inc -I libft
MLBX_H = -I minilibx
MLBX = minilibx/libmlx.a
LIB = libft/libft.a
FLAGS = -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(patsubst %, src/%.o, $(SRC))
C_FLAGS = gcc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx
	@make -C libft fclean
	@make -C libft
	@$(C_FLAGS) $(OBJ) $(LIB) $(MLBX) $(FLAGS) -o $(NAME)
	@echo "Be prepared to enter the Matrix..."

src/%.o: src/%.c
	@$(C_FLAGS) $(LIB_H) $(MLBX_H) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make clean -C minilibx
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all
