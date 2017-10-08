/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:15:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 20:33:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		read_flags(t_parse *parser, int av, char **ac)
{
	int		i;

	i = 1;
	while (i < av)
	{
		if (ft_strequ("--debug", ac[i]))
			parser->debug = 1;
		else
			syntax_error(ac[i], MSG_UNKNOWN_FLAG, 0);
		i++;
	}
}

/*
** Free the parse structure and create the engine structure
*/

static t_engine	get_engine(t_parse *parser)
{
	t_engine		engine;
	t_room_parse	*tmp;
	t_room_parse	*fst;

	engine.nb_ants = parser->nb_ants;
	engine.nb_rooms = parser->nb_rooms;
	engine.rooms = parser->rooms;
	engine.debug = parser->debug;
	engine.nb_paths = 0;
	fst = parser->room;
	while (fst)
	{
		tmp = fst->next;
		ft_memdel((void **)&fst);
		fst = tmp;
	}
	parser->room = NULL;
	return (engine);
}

static void		dispatch_line(char *line, t_parse *parser)
{
	if (is_command(line))
		dispatch_command(line, parser);
	else if (is_room(line, parser))
		parse_room(line, parser, 0, 0);
	else if (is_pipe(line, parser))
	{
		if (!parser->pipe_found)
			parse_rooms_to_tab(line, parser);
		parse_pipe(line, parser);
	}
	else if (!is_comment(line))
		syntax_error(line, MSG_UNKNOWN_SETTING, parser->nb_line);
	else if (is_comment(line))
		ft_strdel(&line);
}

int				main(int av, char **ac)
{
	char		*line;
	t_parse		parser;
	t_engine	engine;

	init_parser(&parser);
	read_flags(&parser, av, ac);
	handle_potential_comments(&line, &parser);
	parser.nb_ants = parse_ants(line);
	ft_strdel(&line);
	while (read_line(&line, &parser) > 0)
		dispatch_line(line, &parser);
	handle_errors_final(parser);
	print_buffer(&parser);
	engine = get_engine(&parser);
	start_engine(&engine);
	return (0);
}
