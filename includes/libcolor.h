/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:30:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:30:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLOR_H
# define LIBCOLOR_H
# include <stdlib.h>

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

t_color				*color_new
						(unsigned char r, unsigned char g, unsigned char b);
void				color_del(t_color **addr);
t_color				color_get(unsigned char r,
						unsigned char b, unsigned char g, unsigned char a);
unsigned int		color_convert(t_color color);
t_color				color_average(t_color a, t_color b);
t_color				color_step(t_color c_a,
						t_color c_b, int nbr_stp, int act_stp);

#endif
