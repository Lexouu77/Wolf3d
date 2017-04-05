/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player	*player_new(t_2d_pnt pos, t_2d_vec view_dir)
{
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->pos = pos;
	new->view_dir = view_dir;
	new->movement_x = 0;
	new->movement_y = 0;
	new->view_move = 0;
	return (new);
}
