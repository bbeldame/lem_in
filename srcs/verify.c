/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:38:26 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 13:48:34 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_comment(char *line, t_env *env)
{
	return (*line && line[0] == '#' && line[1] != '#');
}

int		is_command(char *line, t_env *env)
{
	return (*line && line[0] == '#' && line[1] == '#');
}

int		is_room(char *line, t_env *env)
{
	char	**parsed_line;
	int		len;

	parsed_line = ft_strsplit(line, ' ');
	len = len_of_tab(parsed_line);
	printf("cool\n");
	if (len != 3)
	{
		if (len > 3)
			unknown_setting(line, env->nb_line);
		free_splited_str(parsed_line);
		return (0);
	}
	if (ft_strchr(line, '-'))
		syntax_error(line, "Rooms cannot contains '-'", env->nb_line);
	if (line[0] == 'L')
		syntax_error(line, "Rooms cannot stats with 'L'", env->nb_line);
	if (!verify_int_room_coor(parsed_line))
		syntax_error(line, "Rooms coors must be unsigned integers", env->nb_line);		
	free_splited_str(parsed_line);
	return (1);
}

int		is_pipe(char *line, t_env *env)
{
	return (0);
}
