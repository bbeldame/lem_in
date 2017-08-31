/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 20:39:19 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 22:28:44 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_ants(char *str)
{
	int				i;
	intmax_t		ants;

	if (ft_strlen(str) == 0)
		syntax_error(str, "First line cannot be null", 1);
	if (str[0] && str[0] == '-')
		syntax_error(str, "The number of ants cannot be negative", 1);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			syntax_error(str, "Ants badly formatted", 1);
	}
	if (ft_strlen(str) > 12)
		syntax_error(str, "Too much ants", 1);
	ants = ft_atoll(str);
	if (ants == 0)
		syntax_error(str, "The number of ants cannot be zero", 1);
	if (ants > 2147483647)
		syntax_error(str,
			"The number of ants cannot be superior to INT_MAX", 1);
	return (ants);
}
