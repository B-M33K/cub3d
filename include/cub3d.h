/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:43:45 by obahi             #+#    #+#             */
/*   Updated: 2023/12/14 11:00:59 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define MINI_MAP_WIDTH 200
# define MINI_MAP_HEIGHT 200
# define SCALE 5
# define SCREAN_WIDTH 1280
# define SCREAN_HEIGHT 720
# define TILE_SIZE 32
# define PLAYER_SIZE 8

typedef struct s_map
{
	bool		n;
	bool		s;
	bool		w;
	bool		e;
	int			cols;
	int			rows;
	int			width;
	int			height;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
	char		**grid;
	char		**grid_fill;
}	t_map;

typedef struct s_player
{
	int			x_mini_map;
	int			y_mini_map;
	double		x;
	double		y;
	int			mv_speed;
	int			walk_direction;
	int			turn_direction;
	int			rot_direction;
	double		rot_angle;
	double		rot_speed;
	double		fov;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	x_collision;
	double	y_collision;
	double	d;
	double	x_offset;
	int		down;
	int		right;
	int		v_collision;
	double	wall_height;
}	t_ray;

typedef struct s_cub_file
{
	char	**cub_file;
	int		line_count;
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	floor;
	bool	ceiling;
}	t_cub_file;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_cub_file		*cub_file;
	char			*tex[2][2];
	int				ceiling;
	int				floor;
	t_map			*map;
	t_player		*p;
	int				num_rays;
	t_ray			*rays;
	mlx_texture_t	*textures[2][2];
}	t_game;

typedef struct s_point
{
	int		x0;
	int		y0;
	double	x;
	double	y;
}	t_point;

typedef struct s_cercle
{
	t_point	omega;
	int		radius;
}	t_cercle;

typedef struct s_var
{
	mlx_texture_t	*t;
	int				m;
	int				c;
	int				j;
	double			y_ratio;
	double			x_ratio;
	int				wall_offset;
	int				t_x;
	int				t_y;
	int				y;
}	t_var;

t_cub_file	*ft_get_all_cub_file(t_game *g, char *file);
int			ft_check_cub_ext(char *cub_file);
int			ft_check_elements(t_game *g);
int			ft_file_len(t_game *g, char *cub_file);
void		ft_assign_elements(char c, char c2, char c3, t_game *g);
void		ft_elements_error(char c, char c2, char c3, t_game *g);
void		ft_get_map(t_game *g);
int			ft_fill_map(t_game *g, bool player);
void		ft_clean_all(t_game *g, t_cub_file *cub_file);
int			ft_count_elements(t_game *g, int count);
void		ft_find_player(t_game *g);
void		ft_copy_map(t_game *g);
int			ft_check_is_closed(t_game *g);
void		ft_not_closed_and_clean(t_game *g);
void		ft_parse_and_get_textures(t_game *g);
void		ft_parse_colors(t_game *g);
void		ft_parse_colors(t_game *g);
int			ft_assign_rgb_c_f(t_game *g, char **rgb_final, int flag);
void		ft_check_numbers_rgb(char **rgb, t_game *g);
void		ft_clean_all_rgb_(char **rgb, char **rgb_final, t_game *g);
void		ft_clean_all_rgb(char **rgb, char **rgb_final);
int			ft_is_player(t_game *g, int i, int j);
void		ft_free_map(char **map);
int			ft_find_map(t_game *g);
void		ft_not_closed_and_clean(t_game *g);
int			ft_above_3_digits(char **rgb, char **rgb_final, int j, t_game *g);
void		ft_draw_player(t_game *g);
void		ft_draw_minimap(t_game *g);
t_game		*ft_game_init(char *file, t_cub_file *cub_file, t_map *map);
void		ft_hook(void *param);
void		ft_update_player(t_game *g);
void		ft_draw(t_game *g);
void		ft_update(t_game *g);
void		ft_key_press(void *param);
t_ray		ft_ray(double ray_angle);
void		ft_rays(t_game *g);
double		ft_norm_angle(double angle);
void		ft_cast_ray(t_game *g, int i);
void		ft_cast_rays(t_game *g);
double		ft_distance(double xa, double ya, double xb, double yb);
void		ft_render_walls(t_game *g);
int			ft_rgba_color(int r, int g, int b, int a);
void		ft_draw_background(t_game *g);
void		ft_cast_h_ray(t_game *g, int i, double d[3]);
void		ft_cast_v_ray(t_game *g, int i, double d[3]);
int			ft_get_r(int rgba);
int			ft_get_g(int rgba);
int			ft_get_b(int rgba);
int			ft_get_a(int rgba);
void		ft_rays_init(t_game *g);
int			ft_out_of_bound(t_map	*map, double x, double y);
int			ft_is_wall(t_map *map, int x, int y);
void		ft_draw_stripe(t_game *g, int i);
void		ft_mlx_new_image(t_game *g);
int			ft_mlx_load_textures(t_game *g);
void		ft_mlx_init(t_game *g);
void		ft_clear_all(t_game *g);
void		ft_player_init(t_game *g, int i, int j);
void		ft_mlx_delete_tex(t_game *g);
int			ft_check_if_only_one_num(char **rgb);

#endif