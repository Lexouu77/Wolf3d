/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	exeption(t_env *par, t_2d_pnt a, t_2d_pnt b, unsigned int color)
{
	double coef;

	coef = (b.x - a.x) / (b.y - a.y);
	while ((int)a.y != (int)b.y)
	{
		img_putpixel(par, a.x, a.y, color);
		if (a.y < b.y)
		{
			a.x += coef;
			a.y++;
		}
		else
		{
			a.x -= coef;
			a.y--;
		}
	}
}

void		img_putline(t_env *par, t_2d_pnt a, t_2d_pnt b, unsigned int color)
{
	double	coef;

	coef = (b.y - a.y) / (b.x - a.x);
	if (-1 <= coef && coef <= 1)
	{
		while ((int)a.x != (int)b.x)
		{
			img_putpixel(par, a.x, a.y, color);
			if (a.x < b.x)
			{
				a.y += coef;
				a.x++;
			}
			else
			{
				a.y -= coef;
				a.x--;
			}
		}
	}
	else
		exeption(par, a, b, color);
}
