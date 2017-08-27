/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 20:39:19 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/27 16:02:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_ants(const char *str)
{
	int		i;
	int		ants;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			err_found("bad ants format");
	}
	ants = ft_atoi(str);
	if (ants == 0)
		err_found("number of ants cannot be 0");
	return (ants);
}
