/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 22:13:55 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 19:37:38 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		continue_moving(t_engine *engine)
{
	int		index_last;
	int		end_index;
	int		i;

	i = 0;
	while (i < engine->nb_paths)
	{
		index_last = engine->nb_ants - i - 1;
		if (index_last < 0)
			return (0);
		end_index = engine->paths[engine->ants[index_last].path_chosen][0];
		if (engine->ants[index_last].cur_pos != end_index)
			return (1);
		i++;
	}
	return (0);
}

int		get_index_lower(int nb_paths, int ant_nb)
{
	int		tmp;

	tmp = ant_nb;
	while (tmp - nb_paths >= 0)
		tmp -= nb_paths;
	return (tmp);
}
