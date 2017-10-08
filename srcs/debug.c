/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 19:49:01 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 19:52:53 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	display_paths(t_engine *engine)
{
	int		i;
	int		j;

	i = 0;
	while (i < engine->nb_paths)
	{
		j = 1;
		ft_putstr("PATH NUMBER ");
		ft_putnbr(i);
		ft_putstr(" has as a dist : ");
		ft_putnbr(engine->paths[i][0]);
		ft_putstr(" and is : ");
		while (j < engine->paths[i][0])
		{
			ft_putstr(engine->rooms[engine->paths[i][j]].name);
			ft_putchar('-');
			j++;
		}
		ft_putstr(engine->rooms[engine->paths[i][j]].name);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
