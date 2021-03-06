/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_texture(t_env *env, int *nb_texture)
{
	(env->ray.inter.x == -1) ? (env->ray.inter.x = env->ray.o.x) : 0;
	*nb_texture = env->map.map[(int)(env->ray.inter.y / BLOCK)]
							[(int)(env->ray.inter.x / BLOCK)] - 48;
	if (*nb_texture == 8)
	{
		env->ev_frame = 1;
		*nb_texture = env->frame;
	}
}

static void	render_texture(t_env *env, int col, double down, double nb_pixel)
{
	int		nb_texture;
	double	percent_width;
	int		col_t;
	double	x;
	double	y;

	env->i = (down > HEIGHT) ? down - HEIGHT : 0;
	init_texture(env, &nb_texture);
	percent_width = (env->ray.col == 1) ?
		(int)(env->ray.inter.y / BLOCK) - env->ray.inter.y / BLOCK :
		(int)(env->ray.inter.x / BLOCK) - env->ray.inter.x / BLOCK;
	col_t = fabs(env->textures[nb_texture].width * percent_width);
	x = col_t * env->textures[nb_texture].bpp;
	y = (double)env->textures[nb_texture].height / nb_pixel;
	while (env->i < nb_pixel && env->i < down)
	{
		img_putpixel(env, col, (int)down - env->i,
			*(unsigned int*)(env->textures[nb_texture].data +
			(int)x + (int)(env->textures[nb_texture].height - 1 - env->i * y) *
			env->textures[nb_texture].sl));
		++env->i;
	}
}

void		wolf3d_render(t_env *env, int col, unsigned int color)
{
	double	up;
	double	down;
	double	nb_pixel;

	if (env->dist != 0)
	{
		up = (HEIGHT / 2) - HEIGHT * 4 / env->dist;
		down = (HEIGHT / 2) + HEIGHT * 4 / env->dist;
		nb_pixel = down - up;
		if (env->ev_textures == 0)
		{
			(up <= 0) ? (up = -1) : 0;
			(down > HEIGHT) ? (down = HEIGHT) : 0;
			img_putline(env,
					(t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, up}, color);
			img_putline(env,
					(t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, down}, color);
		}
		else
			render_texture(env, col, down, nb_pixel);
	}
}
