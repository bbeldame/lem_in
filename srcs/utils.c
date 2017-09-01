/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:40:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/01 14:41:58 by bbeldame         ###   ########.fr       */
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
		ft_putstr("Read Error on open");
		exit(3);
	}
	if (res == -1)
	{
		ft_putstr("Read Error : ");
		ft_putstr("\" at line ");
		ft_putnbr(parser->nb_line);
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
}
