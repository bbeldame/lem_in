/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:40:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/04 20:42:04 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	parser->start_found = 0;
	parser->end_found = 0;
	parser->pipe_found = 0;
	parser->room = NULL;
}
