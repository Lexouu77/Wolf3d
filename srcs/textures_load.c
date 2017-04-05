/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	textures_load(t_env *env, int nbr, char *path)
{
	env->textures[nbr].ptr = mlx_xpm_file_to_image(env->mlx,
		path, &env->textures[nbr].width, &env->textures[nbr].height);
	env->textures[nbr].data = mlx_get_data_addr(env->textures[nbr].ptr,
			&env->textures[nbr].bpp, &env->textures[nbr].sl,
			&env->textures[nbr].ed);
	env->textures[nbr].bpp /= 8;
	return (1);
}
