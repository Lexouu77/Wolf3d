/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_block(t_env *env, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK)
	{
		while (j < BLOCK)
		{
			img_putpixel(env, x * BLOCK + j, y * BLOCK + i, color);
			++j;
		}
		j = 0;
		++i;
	}
}

void		wolf3d_map_draw(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env->map.map[i])
	{
		while (env->map.map[i][j])
		{
			draw_block(env, j, i, color_convert(env->map.color[i][j]));
			++j;
		}
		j = 0;
		++i;
	}
}
