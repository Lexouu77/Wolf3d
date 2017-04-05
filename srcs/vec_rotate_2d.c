/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vec_rotate_2d(t_2d_vec *vec, double angle)
{
	double	tmp_x;

	tmp_x = vec->x;
	angle = angle * M_PI / 180;
	vec->x = vec->x * cos(angle) - vec->y * sin(angle);
	vec->y = vec->y * cos(angle) + tmp_x * sin(angle);
}
