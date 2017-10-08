/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:40:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 19:48:39 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	verify_that_pipe_does_not_already_exists(char *line, t_room room,
	int index, t_parse *parser)
{
	int		i;

	i = 0;
	while (i < room.nb_paths)
	{
		if (room.paths[i] == index)
			syntax_error(line, MSG_PIPE_ALREADY_EXISTS, parser->nb_line);
		i++;
	}
}

int		read_line(char **line, t_parse *parser)
{
	int		res;

	parser->nb_line++;
	res = get_next_line(0, line);
	if (res == -1 && parser->nb_line == 1)
	{
		ft_putendl_fd("Read Error on open", 2);
		exit(3);
	}
	if (res == -1)
	{
		ft_putstr_fd("Read Error : ", 2);
		ft_putstr_fd("\" at line ", 2);
		ft_putnbr_fd(parser->nb_line, 2);
		exit(3);
	}
	add_to_buffer(*line, parser);
	return (res);
}

void	init_parser(t_parse *parser)
{
	parser->nb_line = 0;
	parser->nb_ants = 0;
	parser->start_found = 0;
	parser->end_found = 0;
	parser->debug = 0;
	parser->pipe_found = 0;
	parser->room = NULL;
	parser->nb_rooms = 0;
}
