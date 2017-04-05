/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_full_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_full_line(t_env *env, char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
			wolf3d_exit(&env, "Map need to be closed");
		++i;
	}
}

void	check_extremity(t_env *env, char **line)
{
	int	i;

	i = 0;
	if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
		wolf3d_exit(&env, "Map need to be closed");
	while ((*line)[i] != '\0')
		++i;
	--i;
	if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
		wolf3d_exit(&env, "Map need to be closed");
}
