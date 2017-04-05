/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_is_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_map_is_wall(t_env *env, t_2d_pnt a)
{
	if (ft_isdigit(env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)]))
		return (1);
	return (0);
}

int	wolf3d_player_colision(t_env *env, t_2d_pnt a)
{
	if (ft_isdigit(env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)])
			&& env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] != '2')
		return (1);
	return (0);
}
