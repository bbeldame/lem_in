/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:27:58 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/04 22:57:27 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		print_ant(t_engine *engine, int index)
{
	int index_of_room;
	int index_of_path;

	index_of_path = engine->ants[index].path_chosen;
	index_of_room = engine->paths[index_of_path][engine->ants[index].cur_pos];
	ft_putchar('L');
	ft_putnbr(index + 1);
	ft_putchar('-');
	ft_putstr(engine->rooms[index_of_room].name);
	return (1);
}

static int		maybe_print_ant(t_engine *engine, int index)
{
	int		index_next_ant;
	int		index_prev_ant;

	ft_putnbr(index);
	if (engine->ants[index].cur_pos ==
		engine->paths[engine->ants[index].path_chosen][0])
		return (0);
	if (engine->ants[index].cur_pos != 1)
	{
		engine->ants[index].cur_pos += 1;
		return (print_ant(engine, index));
	}
	index_next_ant = index + engine->nb_paths;
	if (index_next_ant >= engine->nb_ants)
	{
		engine->ants[index].cur_pos += 1;
		return (print_ant(engine, index));
	}
	printf("engine->ants[index_next_ant].cur_pos = %d\n", engine->ants[index_next_ant].cur_pos);
	if (engine->ants[index_next_ant].cur_pos != 1)
	{
		ft_putstr("cc\n");
		engine->ants[index].cur_pos += 1;
		return (print_ant(engine, index));
	}
	index_prev_ant = index - engine->nb_paths;
	return (0);
}

static void		move_ants(t_engine *engine)
{
	int		ant;
	int		printed;

	while (continue_moving(engine))
	{
		ant = 0;
		printed = 0;
		while (ant < engine->nb_ants)
		{
			if (printed > 0)
				ft_putchar(' ');
			printed += maybe_print_ant(engine, ant);
			ant++;
		}
		ft_putchar('\n');
	}
}

static t_ant	create_ant(t_engine *engine, int ant_nb)
{
	t_ant	new_ant;
	int		i_path;
	int		best_path_found;

	i_path = engine->nb_paths;
	new_ant.cur_pos = 1;
	best_path_found = 0;
	while (i_path != 0 && best_path_found == 0)
	{
		if (ant_nb % i_path == 0)
		{
			new_ant.path_chosen = i_path - 1;
			best_path_found = 1;
		}
		i_path--;
	}
	if (best_path_found == 0)
		new_ant.path_chosen = 0;
	return (new_ant);
}

void			init_ants(t_engine *engine)
{
	int		i;

	engine->ants = (t_ant *)semalloc(sizeof(t_ant) * engine->nb_ants);
	i = 0;
	while (i <= engine->nb_ants)
	{
		engine->ants[i] = create_ant(engine, i + 1);
		i++;
	}

	i = 0;
	while (i < engine->nb_ants)
	{
		printf("The ant number %d will go in the path number %d\n", i + 1, engine->ants[i].path_chosen);
		i++;
	}
	move_ants(engine);
}