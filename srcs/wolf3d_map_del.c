/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:51 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_map_del(t_map *map)
{
	int	i;

	i = -1;
	if (map->map)
	{
		while (map->map[++i] != NULL)
			(map->map[i]) ? free(map->map[i]) : 0;
		(map->map) ? free(map->map) : 0;
	}
	i = -1;
	if (map->color)
	{
		while (map->color[++i] != NULL)
			(map->color[i]) ? free(map->color[i]) : 0;
		(map->color) ? free(map->color) : 0;
	}
}
