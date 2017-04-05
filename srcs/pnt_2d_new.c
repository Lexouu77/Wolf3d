/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_2d_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:47 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_2d_pnt	*pnt_2d_new(double x, double y)
{
	t_2d_pnt	*new;

	new = (t_2d_pnt*)malloc(sizeof(t_2d_pnt));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
