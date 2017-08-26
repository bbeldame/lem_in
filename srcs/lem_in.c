/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:15:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/26 20:39:00 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		dispatch_line(const char *line)
{

}

int   main(void)
{
	char	*line;
	t_env	env;

	if (get_next_line(0, &line) != 0)
		err_found("error on the first line");
	env.nb_ants = parse_ants(line);
	while (get_next_line(0, &line) > 0)
	{

		ft_putendl(line);
	}
	return (0);
}