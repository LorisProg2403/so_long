/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:29 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/28 19:22:53 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	is_ber(const char *av)
{
	char	*s;

	s = ft_strrchr(av, '.');
	if (s)
		return (!ft_strcmp(s, ".ber"));
	return (false);
}

int	main(int ac, char **av)
{
	t_game	game;

	(void)av;
	if (ac == 2 && !is_ber(av[1]))
		endgame("Wrong format for the map!", &game, error);
	else if (ac > 2)
		endgame("Can't have more than one files!", &game, error);
	else if (ac == 2 && is_ber(av[1]))
		init_game(&game, av[1]);
	endgame("Please give a file!", &game, error);
	return (0);
}
