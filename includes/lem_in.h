/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 22:30:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define RED "\x1B[31m"
# define NC "\033[0m"

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

/*
** Parse
*/

int						parse_ants(char *str);

/*
** Verify
*/

int						is_room(char *line, t_env *env);
int						is_pipe(char *line, t_env *env);
int						is_command(char *line, t_env *env);
int						is_comment(char *line, t_env *env);

/*
** Errors handling
*/

void					syntax_error(char *line, char *explain, int nbline);
void					unknown_setting(char *line, int nbline);

/*
** Utils
*/

int						verify_rooms_format(char **splited_s,
							char *line, t_env *env);
int						read_line(char **line, t_env *env);

/*
** Buffer
*/

void					add_to_buffer(char *line, t_env *env);
void					print_buffer(t_env *env);

#endif
