/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:49:26 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/30 00:00:03 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		display_engine(t_engine engine)
{
	int		i;
	int		j;

	i = 0;
	while (i < engine.nb_rooms)
	{
		ft_putstr("The room ");
		ft_putstr(engine.rooms[i].name);
		if (engine.rooms[i].nb_paths > 1)
			ft_putendl(" have paths to the rooms : ");
		else
			ft_putendl(" have a path to the room : ");
		j = 0;
		while (j < engine.rooms[i].nb_paths)
		{
			ft_putstr(" * ");
			ft_putendl(engine.rooms[engine.rooms[i].paths[j]].name);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
