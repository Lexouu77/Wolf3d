/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:18:01 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:34:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

void	color_del(t_color **addr)
{
	if (*addr)
		free(*addr);
	*addr = NULL;
}
