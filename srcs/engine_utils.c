/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:13:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/01 22:03:14 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		used_room(t_engine *engine, int i_room)
{
	int		i;
	int		j;

	i = 0;
	while (i < engine->nb_paths)
	{
		j = 1;
		while (engine->paths[i][j] != 1)
		{
			if (engine->paths[i][j] == i_room)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}