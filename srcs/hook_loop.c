/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:42 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_loop(t_env *env)
{
	(env->player.movement_y == -1) ? wolf3d_player_move
(env, SPEED * env->player.view_dir.x, SPEED * env->player.view_dir.y) : 0;
	(env->player.movement_y == 1) ? wolf3d_player_move
(env, -SPEED * env->player.view_dir.x, -SPEED * env->player.view_dir.y) : 0;
	(env->player.movement_x == 1) ? wolf3d_player_move
(env, -SPEED * env->player.view_dir.y, SPEED * env->player.view_dir.x) : 0;
	(env->player.movement_x == -1) ? wolf3d_player_move
(env, SPEED * env->player.view_dir.y, -SPEED * env->player.view_dir.x) : 0;
	(env->player.view_move == 1)
		? vec_rotate_2d(&env->player.view_dir, -2 * SPEED_CAM) : 0;
	(env->player.view_move == -1)
		? vec_rotate_2d(&env->player.view_dir, 2 * SPEED_CAM) : 0;
	hook_expose(env);
	return (1);
}
