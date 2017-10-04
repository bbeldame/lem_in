/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 22:13:55 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/04 22:36:35 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		continue_moving(t_engine *engine)
{
	int		index_last;
	int		end_index;

	index_last = engine->nb_ants - 1;
	end_index = engine->paths[engine->ants[index_last].path_chosen][0];
	if (engine->ants[index_last].cur_pos != end_index)
		return (1);
	return (0);
}