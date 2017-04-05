/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_player_init(t_env *env)
{
	int	j;

	env->i = 0;
	j = 0;
	env->player.movement_x = 0;
	env->player.movement_y = 0;
	env->player.view_dir.x = 0;
	env->player.view_dir.y = 1 * BLOCK;
	env->player.view_move = 0;
	while (env->map.map[(int)(env->i / BLOCK)])
	{
		while (env->map.map[(int)(env->i / BLOCK)][(int)(j / BLOCK)])
		{
			if (env->map.map[(int)(env->i / BLOCK)][(int)(j / BLOCK)] == '#')
			{
				env->player.pos.x = (double)j + 0.501;
				env->player.pos.y = (double)env->i + 0.501;
				return (1);
			}
			++j;
		}
		j = 0;
		++env->i;
	}
	return (0);
}
