/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:15:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 22:43:51 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		dispatch_line(char *line, t_env *env)
{
	if (is_command(line))
		ft_putendl("Command");
	else if (is_room(line, env))
		ft_putendl("Room");
	else if (is_pipe(line, env))
		ft_putendl("Pipe");
	else if (!is_comment(line))
		unknown_setting(line, env->nb_line);
	free(line);
}

int				main(void)
{
	char	*line;
	t_env	env;

	env.nb_line = 0;
	read_line(&line, &env);
	env.nb_ants = parse_ants(line);
	printf("Number of ants is %d\n", env.nb_ants);
	ft_strdel(&line);
	while (read_line(&line, &env) > 0)
	{
		dispatch_line(line, &env);
	}
	print_buffer(&env);
	// move_ants(env);
	return (0);
}
