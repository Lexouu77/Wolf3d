/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_2d_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:47 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_2d_pnt	pnt_2d_get(double x, double y)
{
	t_2d_pnt	new;

	new.x = x;
	new.y = y;
	return (new);
}