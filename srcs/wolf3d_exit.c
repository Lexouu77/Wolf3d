/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_exit(t_env **env, char *str)
{
	if (*env)
	{
		wolf3d_map_del(&(*env)->map);
		if ((*env)->img)
			mlx_destroy_image((*env)->mlx, (*env)->img);
		if ((*env)->win)
			mlx_destroy_window((*env)->mlx, (*env)->win);
		(*env) ? free(*env) : 0;
		(*env) = NULL;
	}
	ft_putendl(str);
	exit(0);
}
