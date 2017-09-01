/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 21:40:12 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/31 21:05:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	syntax_error(char *line, char *explain, int nbline)
{
	ft_putstr_fd(RED"Syntax Error : ", 2);
	ft_putstr_fd(explain, 2);
	ft_putstr_fd(" on \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\" at line ", 2);
	ft_putnbr_fd(nbline, 2);
	ft_putchar_fd('\n', 2);
	exit(3);
}

void	unknown_setting(char *line, int nbline)
{
	ft_putstr_fd(RED"Unknown setting \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\" at line ", 2);
	ft_putnbr_fd(nbline, 2);
	ft_putchar_fd('\n', 2);
	exit(3);
}
