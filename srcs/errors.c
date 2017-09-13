/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:40:12 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/13 20:40:31 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	errors_before_parsing_rooms_to_tab(char *line, t_parse *parser)
{
	if (parser->start_found == 0)
		syntax_error(line, MSG_NO_START_ROOM, parser->nb_line);
	if (parser->end_found == 0)
		syntax_error(line, MSG_NO_END_ROOM, parser->nb_line);
}

void	handle_errors_rooms(char *line, char **parsed_line, t_parse *parser)
{
	if (ft_count_spaces(line) != 2)
		syntax_error(line, MSG_TOO_MUCH_SPACE, parser->nb_line);
	if (ft_strchr(line, '\t'))
		syntax_error(line, MSG_ROOM_TAB, parser->nb_line);
	if (parser->pipe_found)
		syntax_error(line, MSG_ROOM_AFTER_PIPE, parser->nb_line);
	if (ft_strchr(line, '-'))
		syntax_error(line, MSG_ROOM_HYPHEN, parser->nb_line);
	if (line[0] == 'L')
		syntax_error(line, MSG_SETT_START_L, parser->nb_line);
	verify_rooms_format(parsed_line, line, parser);
	if (rooms_contains_name(parsed_line[0], parser))
		syntax_error(line, MSG_SAME_NAME, parser->nb_line);
	if (rooms_contains_coor(ft_atoi(parsed_line[1]),
		ft_atoi(parsed_line[2]), parser))
		syntax_error(line, MSG_SAME_COOR, parser->nb_line);
}

void	syntax_error(char *line, char *explain, int nbline)
{
	ft_putstr_fd(RED"Syntax Error "NC, 2);
	ft_putstr_fd(explain, 2);
	ft_putstr_fd(CYAN" (on \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\" at line ", 2);
	ft_putnbr_fd(nbline, 2);
	ft_putstr_fd(")\n", 2);
	exit(3);
}
