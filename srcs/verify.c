/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:38:26 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/01 18:22:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_comment(char *line)
{
	return (*line && line[0] == '#');
}

int		is_command(char *line)
{
	return (*line && line[0] == '#' &&
		line[1] == '#' && ft_strlen(line + 2) > 0);
}

int		is_room(char *line, t_parse *parser)
{
	char	**parsed_line;
	int		len;

	parsed_line = ft_strsplit(line, ' ');
	len = len_of_tab(parsed_line);
	if (len != 3)
	{
		if (len > 3)
			syntax_error(line, MSG_UNKNOWN_SETTING, parser->nb_line);
		free_splited_str(parsed_line);
		return (0);
	}
	handle_errors_rooms(line, parsed_line, parser);
	free_splited_str(parsed_line);
	return (1);
}

int		is_pipe(char *line, t_parse *parser)
{
	char	**parsed_line;
	int		len;

	parsed_line = ft_strsplit(line, '-');
	len = len_of_tab(parsed_line);
	if (len != 2)
	{
		free_splited_str(parsed_line);
		return (0);
	}
	if (ft_strcmp(parsed_line[0], parsed_line[1]) == 0)
		syntax_error(line, MSG_PIPE_SAME, parser->nb_line);
	free_splited_str(parsed_line);
	// verify that the rooms does exist
	return (1);
}
