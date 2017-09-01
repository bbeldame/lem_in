/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/01 18:16:29 by bbeldame         ###   ########.fr       */
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

/*
** General Errors
*/

# define UNKNOWN_SETTING "This format does not exist"
# define UNKNOWN_COMMAND "This command does not exist"

/*
** Rooms Parser Errors
*/

# define MSG_ROOM_FORMAT "Rooms format is a-Z0-9_"
# define MSG_ROOM_CONT_UINT "Rooms coors must be unsigned integers"
# define MSG_COOR_SUPP_INT "The coordinates cannot be superior to INT_MAX"
# define MSG_SETT_START_L "Rooms name cannot start with 'L'"
# define MSG_ROOM_HYPHEN "Rooms settings cannot contains '-'"
# define MSG_SAME_NAME "Rooms cannot have the same name"
# define MSG_SAME_COOR "Rooms cannot have the same coordinates"
# define MSG_ROOM_AFTER_PIPE "Rooms cannot be given after pipes"

/*
** Ants Parser Errors
*/

# define MSG_NULL "First line cannot be null"
# define MSG_ANTS_NEG "The number of ants cannot be negative"
# define MSG_FORMAT "Ants badly formatted"
# define MSG_TOO_MUCH "Too much ants"
# define MSG_ZERO "The number of ants cannot be zero"
# define MSG_INT_MAX "The number of ants cannot be superior to INT_MAX"

/*
** Commands Errors
*/

# define MSG_OVERRIDE_START "Cannot have multiple start commands"
# define MSG_OVERRIDE_END "Cannot have multiple end commands"
# define MSG_NO_ROOM_START "The command 'start' wait for a room"
# define MSG_NO_ROOM_END "The command 'end' wait for a room"

/*
** Pipe Parser Errors
*/

# define MSG_PIPE_SAME "Can't make any inception with the pipe"

typedef struct			s_room_parse
{
	int					x;
	int					y;
	int					end;
	int					start;
	char				*name;
	struct s_room_parse	*next;
}						t_room_parse;

typedef struct			s_parse
{
	int					nb_ants;
	int					nb_line;
	int					start_found;
	int					end_found;
	int					pipe_found;
	char				*buffer;
	t_room_parse		*room;
}						t_parse;

/*
** Parse
*/

int						parse_ants(char *str);
void					parse_room(char *line,
							t_parse *parser, int start, int end);
void					dispatch_command(char *line, t_parse *parser);

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

/*
** Utils
*/

int						read_line(char **line, t_parse *parser);
void					init_parser(t_parse *parser);

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

#endif
