/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_2d_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_2d_vec	*vec_2d_new(double x, double y)
{
	t_2d_vec	*new;

	new = (t_2d_vec*)malloc(sizeof(t_2d_vec));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
