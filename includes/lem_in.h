/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/23 20:25:05 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./error_code.h"

# define RED "\x1B[31m"
# define CYAN "\x1b[36m"
# define NC "\033[0m"

typedef struct			s_room_parse
{
	int					x;
	int					y;
	int					end;
	int					start;
	char				*name;
	struct s_room_parse	*next;
}						t_room_parse;

typedef struct			s_room
{
	int					*paths;
	int					start;
	int					end;
	int					nb_paths;
	char				*name;
}						t_room;

typedef	struct			s_engine
{
	int					nb_ants;
	int					nb_rooms;
	t_room				*rooms;
}						t_engine;

typedef struct			s_parse
{
	int					nb_ants;
	int					nb_line;
	int					nb_rooms;
	int					start_found;
	int					end_found;
	int					pipe_found;
	char				*buffer;
	t_room_parse		*room;
	t_room				*rooms;
}						t_parse;

/*
** Parse
*/

int						parse_ants(char *str);
void					parse_room(char *line,
							t_parse *parser, int start, int end);
void					dispatch_command(char *line, t_parse *parser);
void					parse_rooms_to_tab(char *line, t_parse *parser);
t_room					parse_room_from_chained_list(t_room_parse *old_room,
							t_parse *parser);
void					parse_pipe(char *line, t_parse *parser);

/*
** Verify
*/

int						is_room(char *line, t_parse *parser);
int						is_pipe(char *line, t_parse *parser);
int						is_command(char *line);
int						is_comment(char *line);
void					verify_rooms_format(char **splited_s,
							char *line, t_parse *parser);
int						rooms_contains_name(char *name, t_parse *parser);
int						rooms_contains_coor(int x, int y, t_parse *parser);

/*
** Errors handling
*/

void					handle_errors_rooms(char *line,
							char **parsed_line, t_parse *parser);
void					syntax_error(char *line, char *explain, int nbline);
void					errors_before_parsing_rooms_to_tab(char *line,
							t_parse *parser);
void					handle_errors_final(t_parse parser);
void					general_error(char *explain);

/*
** Utils
*/

int						read_line(char **line, t_parse *parser);
void					init_parser(t_parse *parser);
void					verify_that_pipe_does_not_already_exists(char *line,
							t_room room, int index, t_parse *parser);

/*
** Buffer
*/

void					add_to_buffer(char *line, t_parse *parser);
void					print_buffer(t_parse *parser);

/*
** Commands
*/

void					handle_command_start(char *line, t_parse *parser);
void					handle_command_end(char *line, t_parse *parser);

/*
** Display
*/

void					display_engine(t_engine engine);

#endif
