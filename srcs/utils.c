/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:40:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 22:31:09 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** My room name must not contains other characters than a to z,
** A to Z, 0 to 9 and the character _
** Room coordinates must be positive integers, inferior to the INT_MAX
*/

int		verify_rooms_format(char **splited_s, char *line, t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (splited_s[0][x])
	{
		if (!ft_isalnum(splited_s[0][x]) && splited_s[0][x] != '_')
			syntax_error(line, "Rooms format is a-Z0-9_", env->nb_line);
		x++;
	}
	y = 1;
	while (y <= 2)
	{
		x = 0;
		while (splited_s[y][x])
			if (!ft_isdigit(splited_s[y][x++]))
				syntax_error(line,
					"Rooms coors must be unsigned integers", env->nb_line);
		if (ft_atoll(splited_s[y]) > 2147483647 || ft_strlen(splited_s[y]) > 12)
			syntax_error(line,
				"The coordinates of cannot be superior to INT_MAX", 1);
		y++;
	}
	return (1);
}

int		read_line(char **line, t_env *env)
{
	int		res;

	env->nb_line++;
	res = get_next_line(0, line);
	if (res == -1 && env->nb_line == 1)
	{
		ft_putstr("Read Error on open");
		exit(3);
	}
	if (res == -1)
	{
		ft_putstr("Read Error : ");
		ft_putstr("\" at line ");
		ft_putnbr(env->nb_line);
		exit(3);
	}
	add_to_buffer(*line, env);
	return (res);
}
