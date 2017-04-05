/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 07:04:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_start(t_env *env)
{
	event_key(env);
	mlx_expose_hook(env->win, hook_expose, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_loop(env->mlx);
}
