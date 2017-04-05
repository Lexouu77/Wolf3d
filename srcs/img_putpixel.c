/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_putpixel(t_env *env, int x, int y, int color)
{
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int*)(env->data + x * env->bpp + env->sl * y) =
			mlx_get_color_value(env->mlx, color);
}
