/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:18:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:18:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	*color_new(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*new;

	if (!(new = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	new->a = 0;
	return (new);
}
