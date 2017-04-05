/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_draw(t_env *env)
{
	int		i;
	int		j;

	j = 0;
	while (j < PLAYER_SIZE)
	{
		i = -1;
		while (++i < PLAYER_SIZE)
		{
			img_putline(env,
					(t_2d_pnt){env->player.pos.x + i, env->player.pos.y + j},
					(t_2d_pnt){env->player.pos.x + env->player.view_dir.x + i,
					env->player.pos.y + env->player.view_dir.y + j},
					color_convert(color_get(255, 0, 255, 0)));
			img_putpixel(env,
					env->player.pos.x + i,
					env->player.pos.y + j,
					0xffffff);
			img_putpixel(env,
					(env->player.pos.x + env->player.view_dir.x) + i,
					(env->player.pos.y + env->player.view_dir.y) + j,
					0xff00ff);
		}
		++j;
	}
}
