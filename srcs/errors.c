/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:40:12 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/29 22:13:40 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	syntax_error(char *line, char *explain, int nbline)
{
	ft_putstr("Syntax Error : ");
	ft_putstr(explain);
	ft_putstr(" on \"");
	ft_putstr(line);
	ft_putstr("\" at line ");
	ft_putnbr(nbline);
	ft_putchar('\n');
	exit(3);
}

void	unknown_setting(char *line, int nbline)
{
	ft_putstr("Unknown setting \"");
	ft_putstr(line);
	ft_putstr("\" at line ");
	ft_putnbr(nbline);
	ft_putchar('\n');
	exit(3);
}
