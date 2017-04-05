/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:18:01 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:18:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

unsigned int	color_convert(t_color color)
{
	unsigned int	converted;

	*((unsigned char*)&converted + 0) = color.g;
	*((unsigned char*)&converted + 1) = color.b;
	*((unsigned char*)&converted + 2) = color.r;
	*((unsigned char*)&converted + 3) = color.a;
	return (converted);
}
