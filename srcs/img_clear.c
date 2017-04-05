/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:43 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_clear(t_env *env)
{
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if ((env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)) == NULL)
		wolf3d_exit(&env, "img_clear: mlx_new_image");
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->ed);
	env->bpp /= 8;
}
