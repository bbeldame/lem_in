/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:45:56 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 19:12:35 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Depth First Search Algorithm
*/

static void		dfs(t_engine *engine, int index, int dist)
{
	int i;

	if (engine->rooms[index].blocked == 1)
		return ;
	if (engine->rooms[index].dist != -1 && dist > engine->rooms[index].dist)
		return ;
	engine->rooms[index].dist = dist;
	if (index == 0)
		return ;
	i = 0;
	while (i < engine->rooms[index].nb_paths)
	{
		dfs(engine, engine->rooms[index].paths[i], dist + 1);
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

	path = (int *)semalloc(sizeof(int) * engine->nb_rooms + 1);
	index = 0;
	path[0] = engine->rooms[0].dist + 1;
	path[1] = 0;
	i = 2;
	while (index != 1)
	{
		path[i] = get_next_room(engine, index);
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
	engine->rooms[0].dist = -1;
	engine->rooms[1].dist = -1;
	while (i_room < engine->nb_rooms)
	{
		engine->rooms[i_room].dist = -1;
		if (used_room(engine, i_room))
			engine->rooms[i_room].blocked = 1;
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
		dfs(engine, 1, 0);
		if (engine->rooms[0].dist != -1)
		{
			/*
				j = 0;
				while (j < engine->nb_rooms)
				{
					ft_putstr("Room ");
					ft_putstr(engine->rooms[j].name);
					ft_putstr(" has dist of ");
					ft_putnbr(engine->rooms[j].dist);
					if (engine->rooms[j].blocked == 1)
						ft_putstr(" but is blocked");
					ft_putchar('\n');
					j++;
				}
				ft_putstr("==========================\n");
				ft_putstr("==========================\n");
			*/
			engine->nb_paths += 1;
			engine->paths[i] = record_path(engine);
			block_path(engine);
		}
		i++;
	}
	if (engine->nb_paths == 0)
		general_error(MSG_NO_PATH);
	

	// Debug
	/*
	i = 0;
	while (i < engine->nb_paths)
	{
		j = 1;
		ft_putstr("PATH NUMBER ");
		ft_putnbr(i);
		ft_putstr(" has as a dist : ");
		ft_putnbr(engine->paths[i][0]);
		ft_putstr(" and is : ");
		while (j <= engine->paths[i][0])
		{
			ft_putstr(engine->rooms[engine->paths[i][j]].name);
			ft_putchar('-');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	*/
	init_ants(engine);
}
