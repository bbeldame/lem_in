/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:43:58 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/05 20:39:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_buffer(char *line, t_parse *parser)
{
	parser->buffer = ft_strjoin_nl_free(parser->buffer, line);
	if (parser->buffer == NULL)
		err_found("Error : allocation problem");
}

void	print_buffer(t_parse *parser)
{
	ft_putstr(parser->buffer);
	ft_putstr("\n");
}
