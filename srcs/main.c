/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 05:12:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/31 05:12:45 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		env = wolf3d_init(ac, av);
		wolf3d_start(env);
	}
	else
		wolf3d_exit(&env, "Usage:\n./wolf3d path/to/map");
	return (0);
}
