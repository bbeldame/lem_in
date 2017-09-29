/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:45:56 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/30 00:17:10 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Depth First Search Algorithm
*/

void		dfs(t_engine *engine, int index, int dist, int index_calling)
{
	int i;

	engine->rooms[index].visited = 1;
	if ((engine->rooms[index].dist == -1 || dist < engine->rooms[index].dist))
	{
		engine->rooms[index].dist = dist;
		engine->rooms[index].next_room = index_calling;
	}
	ft_putendl(engine->rooms[index].name);
	i = 0;
	while (i < engine->rooms[index].nb_paths)
	{
		if (engine->rooms[engine->rooms[index].paths[i]].visited == 0)
		{
			dfs(engine, engine->rooms[index].paths[i], dist + 1, index);
		}
		i++;
	}
}

void		move_ants(t_engine engine)
{
	int		i;

	dfs(&engine, 1, 0, 0);
	i = 0;
	while (i < engine.nb_rooms)
	{
		ft_putstr("The room ");
		ft_putstr(engine.rooms[i].name);
		ft_putstr(" have as the next room : ");
		if (i != 1)
			ft_putstr(engine.rooms[engine.rooms[i].next_room].name);
		else
			ft_putstr("no one");
		ft_putchar('\n');
		ft_putstr("The dist is set to : ");
		ft_putnbr(engine.rooms[i].dist);
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}
