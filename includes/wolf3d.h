/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:30:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 07:51:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libcolor.h"
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define WIDTH 800
# define HEIGHT 600
# define BLOCK 10
# define SPEED 0.1
# define SPEED_CAM 2
# define LUM 10
# define TITLE "MY FIRST WOLF3D!"
# define PLAYER_SIZE 2
# define PCNT PLAYER_SIZE / 2
# define NB_TEXTURE 10

typedef struct	s_2d_pnt
{
	double	x;
	double	y;
}				t_2d_pnt;

typedef struct	s_2d_vec
{
	double	x;
	double	y;
}				t_2d_vec;

typedef struct	s_2d_ray
{
	t_2d_pnt	o;
	t_2d_vec	dir;
	t_2d_pnt	inter;
	char		col;
}				t_2d_ray;

typedef struct	s_player
{
	t_2d_pnt	pos;
	t_2d_vec	view_dir;
	char		movement_x;
	char		movement_y;
	char		view_move;
}				t_player;

typedef struct	s_map
{
	t_color	**color;
	char	**map;
	int		size_y;
}				t_map;

typedef struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		sl;
	int		ed;
}				t_img;

typedef struct	s_env
{
	int			ac;
	char		**av;
	int			fd;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			ed;
	t_map		map;
	t_player	player;
	t_2d_ray	ray;
	t_2d_ray	ray2;
	int			player_size;
	int			i;
	double		dist;
	t_color		color;
	t_color		prev_right;
	t_color		prev_left;
	char		part_screen;
	char		ev_draw_map;
	char		ev_color;
	char		ev_textures;
	t_img		textures[NB_TEXTURE];
	double		frame;
	char		ev_frame;
	int			size_line;
	double		m;
	double		p;
}				t_env;

t_env			*wolf3d_init(int ac, char **av);
int				wolf3d_exit(t_env **env, char *str);
void			wolf3d_start(t_env *env);
void			wolf3d_map_load(t_env *env);
void			wolf3d_map_del(t_map *map);
void			wolf3d_map_draw(t_env *env);
int				wolf3d_map_is_wall(t_env *env, t_2d_pnt a);
int				wolf3d_player_init(t_env *env);
void			wolf3d_player_draw(t_env *env);
void			wolf3d_player_move(t_env *env, double x, double y);
void			wolf3d_ray_draw
					(t_env *env, t_2d_ray *ray, unsigned int color, char draw);
void			wolf3d_render(t_env *env, int col, unsigned int color);

void			img_putpixel(t_env *env, int x, int y, int color);
void			img_fill_down(t_env *env, t_color color);
void			img_putline(t_env *par, t_2d_pnt a, t_2d_pnt b,
														unsigned int color);
void			img_clear(t_env *env);
void			img_fill_up(t_env *env, double color);

void			event_key(t_env *env);
int				hook_loop(t_env *env);
int				hook_expose(t_env *env);

void			vec_rotate_2d(t_2d_vec *vec, double angle);
t_2d_pnt		*pnt_2d_new(double x, double y);
void			pnt_2d_del(t_2d_pnt **addr);
t_2d_pnt		pnt_2d_get(double x, double y);
t_2d_vec		*vec_2d_new(double x, double y);
void			vec_2d_del(t_2d_vec **addr);
t_2d_vec		vec_2d_get(double x, double y);
int				textures_load(t_env *env, int nbr, char *path);
void			check_full_line(t_env *env, char **line);
void			check_extremity(t_env *env, char **line);
int				wolf3d_player_colision(t_env *env, t_2d_pnt a);
void			assign_x
				(t_env *env, t_2d_ray *ray, double *distx, t_2d_pnt cursor);
void			assign_y
				(t_env *env, t_2d_ray *ray, double *disty, t_2d_pnt cursor);

#endif
