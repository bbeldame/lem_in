/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 20:43:58 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 21:25:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_buffer(char *line, t_env *env)
{
	env->buffer = ft_strjoin_nl_free(env->buffer, line);
	if (env->buffer == NULL)
		err_found("Error : allocation problem");
}

void	print_buffer(t_env *env)
{
	ft_putstr(env->buffer);
	ft_putstr("\n\n");
}
