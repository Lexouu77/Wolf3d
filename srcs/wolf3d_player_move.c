/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_move(t_env *env, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = env->player.pos.x + x;
	new_y = env->player.pos.y + y;
	if (!wolf3d_player_colision(env, (t_2d_pnt){new_x, env->player.pos.y}))
		env->player.pos.x += x;
	if (!wolf3d_player_colision(env, (t_2d_pnt){env->player.pos.x, new_y}))
		env->player.pos.y += y;
}
