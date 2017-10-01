/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:45:56 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/01 21:24:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Depth First Search Algorithm
*/

static void		dfs(t_engine *engine, int index, int dist, int index_calling)
{
	int i;

	engine->rooms[index].visited = 1;
	if ((engine->rooms[index].dist == -1 || dist < engine->rooms[index].dist))
	{
		engine->rooms[index].dist = dist;
		engine->rooms[index].next_room = index_calling;
	}
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

/*
** Record the path like ROOM-ROOM-ROOM
** into an array of int
*/

static int		*record_path(t_engine *engine)
{
	int			*path;
	int			index;
	int			i;

	path = (int *)semalloc(sizeof(int) * engine->nb_rooms);
	index = 0;
	i = 0;
	path[i] = 0;
	i++;
	while (index != 1)
	{
		path[i] = engine->rooms[index].next_room;
		index = path[i];
		i++;
	}
	return (path);
}

/*
** Reset the visited of room and block the path already taken
** We reset the START and END whatever the past paths
*/

static void		block_path(t_engine *engine)
{
	int		i_room;

	i_room = 2;
	engine->rooms[0].visited = 0;
	engine->rooms[0].dist = -1;
	engine->rooms[1].visited = 0;
	engine->rooms[1].dist = -1;
	while (i_room < engine->nb_rooms)
	{
		if (!used_room(engine, i_room))
		{
			engine->rooms[i_room].visited = 0;
			engine->rooms[i_room].dist = -1;
		}
		else
		{
			engine->rooms[i_room].visited = 1;
		}
		i_room++;
	}
}

/*
** After DFS, if the dist of start is -1, it means that
** it did not find any path
*/

void			start_engine(t_engine *engine)
{
	int		i;
	int		j;
	int		possible_paths_nb;

	possible_paths_nb = engine->rooms[0].nb_paths;
	possible_paths_nb = engine->rooms[1].nb_paths < possible_paths_nb ?
		engine->rooms[1].nb_paths : possible_paths_nb;
	engine->paths = (int **)semalloc(sizeof(int *) * possible_paths_nb);
	i = 0;
	while (i < possible_paths_nb)
	{
		dfs(engine, 1, 0, 0);
		if (engine->rooms[0].dist != -1)
		{
			engine->nb_paths += 1;
			engine->paths[i] = record_path(engine);
			block_path(engine);
		}
		i++;
	}

	// Debug
	i = 0;
	while (i < engine->nb_paths)
	{
		j = 0;
		ft_putstr("GONNA PRINT THE PATH = ");
		while (engine->paths[i][j] != 1)
		{
			ft_putstr(engine->rooms[engine->paths[i][j]].name);
			ft_putchar('-');
			j++;
		}
		ft_putstr(engine->rooms[engine->paths[i][j]].name);
		ft_putchar('\n');
		i++;
	}
}
