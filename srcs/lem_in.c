/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:15:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/27 20:12:06 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		dispatch_line(char *line, t_env *env)
{
	ft_putendl(line);
	env->nb_ants = env->nb_ants;
	ft_strdel(&line);
}

int				main(void)
{
	char	*line;
	t_env	env;

	if (get_next_line(0, &line) <= 0)
		err_found("error on the first line");
	env.nb_ants = parse_ants(line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		dispatch_line(line, &env);
	}
	return (0);
}
