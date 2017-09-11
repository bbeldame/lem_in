/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:15:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/11 21:00:35 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
		ft_putendl("Pipe");
	}
	else if (!is_comment(line))
		syntax_error(line, MSG_UNKNOWN_SETTING, parser->nb_line);
}

int				main(void)
{
	char	*line;
	t_parse	parser;

	init_parser(&parser);
	read_line(&line, &parser);
	parser.nb_ants = parse_ants(line);
	printf("Number of ants is %d\n", parser.nb_ants);
	ft_strdel(&line);
	while (read_line(&line, &parser) > 0)
	{
		dispatch_line(line, &parser);
	}
	print_buffer(&parser);
	// move_ants(parser);
	return (0);
}
