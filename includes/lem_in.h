/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/27 20:12:20 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					*tunnels;
}						t_room;

typedef struct			s_env
{
	int					nb_ants;
	int					nb_line;
	char				*buffer;
	t_room				*room;
}						t_env;

typedef struct			s_tmp_room
{
	char				*name;
	int					x;
	int					y;
	struct s_tmp_room	*next;
}						t_tmp_room;

int						parse_ants(const char *str);

#endif
