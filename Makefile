# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obahi <obahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:17:06 by obahi             #+#    #+#              #
#    Updated: 2023/12/13 18:02:34 by obahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g

CFLAGS = -Wall -Wextra -Werror 

MAKE = make

NAME = cub3D

HEADER = include/cub3d.h

SRC_DIR = src

OBJ_DIR = obj

SRC =	src/ft_assign_elements.c \
		src/ft_assign_rgb_c_f.c \
		src/ft_cast_h_ray.c \
		src/ft_cast_ray.c \
		src/ft_cast_rays.c \
		src/ft_cast_v_ray.c \
		src/ft_check_cub_ext.c \
		src/ft_check_elements.c \
		src/ft_check_is_close.c \
		src/ft_check_numbers_rgb.c \
		src/ft_clean.c \
		src/ft_clear_all.c \
		src/ft_color.c \
		src/ft_count_elem.c \
		src/ft_distance.c \
		src/ft_draw.c \
		src/ft_draw_background.c \
		src/ft_draw_minimap.c \
		src/ft_draw_player.c \
		src/ft_draw_stripe.c \
		src/ft_elements_error.c \
		src/ft_file_len.c \
		src/ft_fill_map.c \
		src/ft_game_init.c \
		src/ft_get_all_cub_file.c \
		src/ft_get_map.c \
		src/ft_get_rgba.c \
		src/ft_hook.c \
		src/ft_key_press.c \
		src/ft_mlx_delete_tex.c \
		src/ft_mlx_init.c \
		src/ft_mlx_load_textures.c \
		src/ft_mlx_new_image.c \
		src/ft_norm_angle.c \
		src/ft_parse_colors.c \
		src/ft_parse_textures.c \
		src/ft_pixel_boundries.c \
		src/ft_player.c \
		src/ft_ray.c \
		src/ft_ray_inits.c \
		src/ft_rays.c \
		src/ft_render_walls.c \
		src/ft_update.c \
		src/ft_update_player.c \
		src/main.c \
		src/map_utils.c \
		src/utils.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

GLFW = $(shell brew --prefix glfw)

LIB_GLFW = $(addprefix $(GLFW),/lib)

MLX42_HEADER = MLX42/include/MLX42/MLX42.h

MLX42 = MLX42/build/libmlx42.a
	
LIBFT = libft/libft.a

all : $(OBJ_DIR) $(NAME)

$(MLX42) :
	cmake -S MLX42 -B MLX42/build
	make -C MLX42/build -j4

$(NAME) : $(OBJ) $(MLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX42) -L $(LIB_GLFW) -lglfw $^ -o $@

$(LIBFT) : libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	if [ -d $@ ]; then echo "obj directory exists."; else mkdir -p $(OBJ_DIR); echo "obj directory is created"; fi


mlx_build : $(MLX42)
	cmake -S MLX42 -B build
	make -C MLX42/build -j4

mlx_clean :
	if [ -e "MLX42/build" ]; then make -C MLX42/build clean; fi

mlx_fclean :
	rm -rf MLX42/build

clean : mlx_clean
	make -C libft clean
	$(RM) -rf $(OBJ_DIR)/*.o

fclean : clean mlx_fclean
	make -C libft fclean
	rm -f $(NAME)

libft :
	@make -C libft

git : fclean
	git add .
	git commit -m "$m"
	git push -u origin

re : fclean all

.PHONY : all clean fclean re libft mlx_build mlx_clean mlx_fclean git
	
