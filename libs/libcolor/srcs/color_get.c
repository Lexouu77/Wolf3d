/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:18:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:18:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_get(unsigned char r,
					unsigned char b,
					unsigned char g,
					unsigned char a)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
