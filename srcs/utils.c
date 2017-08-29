/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:00:28 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/29 22:26:08 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	return (res);
}
