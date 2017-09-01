/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 20:39:19 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/01 11:57:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_ants(char *str)
{
	int				i;
	intmax_t		ants;

	if (ft_strlen(str) == 0)
		syntax_error(str, MSG_NULL, 1);
	if (str[0] && str[0] == '-')
		syntax_error(str, MSG_ANTS_NEG, 1);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			syntax_error(str, MSG_FORMAT, 1);
	}
	if (ft_strlen(str) > 12)
		syntax_error(str, MSG_TOO_MUCH, 1);
	ants = ft_atoll(str);
	if (ants == 0)
		syntax_error(str, MSG_ZERO, 1);
	if (ants > 2147483647)
		syntax_error(str, MSG_INT_MAX, 1);
	return (ants);
}
