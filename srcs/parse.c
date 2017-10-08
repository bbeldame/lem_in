/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:02:34 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/08 22:57:49 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	parse_pipe_into_rooms(char *line, int index_a,
	int index_b, t_parse *parser)
{
	int		index_of_new_path;

	verify_that_pipe_does_not_already_exists(line, parser->rooms[index_a],
		index_b, parser);
	verify_that_pipe_does_not_already_exists(line, parser->rooms[index_b],
		index_a, parser);
	index_of_new_path = parser->rooms[index_a].nb_paths;
	parser->rooms[index_a].paths[index_of_new_path] = index_b;
	index_of_new_path = parser->rooms[index_b].nb_paths;
	parser->rooms[index_b].paths[index_of_new_path] = index_a;
	parser->rooms[index_a].nb_paths += 1;
	parser->rooms[index_b].nb_paths += 1;
	ft_strdel(&line);
}

/*
** In a pipe : index_a-index_b
*/

void		parse_pipe(char *line, t_parse *parser)
{
	char	**parsed_line;
	int		index_a;
	int		index_b;
	int		i;

	index_a = -1;
	index_b = -1;
	i = 0;
	parsed_line = ft_strsplit(line, '-');
	while (i < parser->nb_rooms)
	{
		if (ft_strequ(parser->rooms[i].name, parsed_line[0]))
			index_a = i;
		if (ft_strequ(parser->rooms[i].name, parsed_line[1]))
			index_b = i;
		i++;
	}
	if (index_a == -1 || index_b == -1)
		syntax_error(line, MSG_PIPE_NO_ROOM, parser->nb_line);
	free_splited_str(parsed_line);
	parse_pipe_into_rooms(line, index_a, index_b, parser);
}

void		parse_rooms_to_tab(char *line, t_parse *parser)
{
	int				i;
	int				index;
	t_room_parse	*tmp;

	parser->pipe_found = 1;
	errors_before_parsing_rooms_to_tab(line, parser);
	parser->rooms = (t_room *)semalloc(sizeof(t_room) * parser->nb_rooms);
	i = 0;
	tmp = parser->room;
	while (tmp)
	{
		if (tmp->start)
			index = 0;
		else if (tmp->end)
			index = 1;
		else
		{
			index = i + 2;
			i++;
		}
		parser->rooms[index] = parse_room_from_chained_list(tmp, parser);
		tmp = tmp->next;
	}
}

void		parse_room(char *line, t_parse *parser, int start, int end)
{
	char			**parsed_line;
	t_room_parse	*new_room;

	new_room = (t_room_parse *)semalloc(sizeof(t_room_parse));
	parsed_line = ft_strsplit(line, ' ');
	new_room->name = ft_strdup(parsed_line[0]);
	new_room->x = ft_atoi(parsed_line[1]);
	new_room->y = ft_atoi(parsed_line[2]);
	new_room->start = start;
	new_room->end = end;
	new_room->next = parser->room;
	parser->room = new_room;
	parser->nb_rooms = parser->nb_rooms + 1;
	free_splited_str(parsed_line);
	ft_strdel(&line);
}

void		dispatch_command(char *line, t_parse *parser)
{
	if (ft_strequ(line + 2, "start"))
		handle_command_start(line, parser);
	else if (ft_strequ(line + 2, "end"))
		handle_command_end(line, parser);
	else if (ft_strequ(line + 2, "debug"))
	{
		parser->debug = 1;
		ft_strdel(&line);
	}
	else if (ft_strequ(line + 2, "color"))
	{
		parser->color = 1;
		ft_strdel(&line);
	}
	else
		ft_strdel(&line);
}
