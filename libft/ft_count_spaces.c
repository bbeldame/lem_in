/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 17:35:54 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/03 17:36:06 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_spaces(char *str)
{
	int			blanks;

	blanks = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			blanks++;
		str++;
	}
	return (blanks);
}
