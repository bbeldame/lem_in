/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 18:23:35 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/11 21:02:11 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

/*
** General Errors
*/

# define MSG_UNKNOWN_SETTING "This format does not exist"
# define MSG_UNKNOWN_COMMAND "This command does not exist"

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
# define MSG_TOO_MUCH_SPACE "Bad formatted rooms, eg: xxx x x"
# define MSG_ROOM_TAB "No tabs allowed"
# define MSG_NO_START_ROOM "No start room found"
# define MSG_NO_END_ROOM "No end room found"

/*
** Ants Parser Errors
*/

# define MSG_NULL "Lines cannot be null"
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

#endif
