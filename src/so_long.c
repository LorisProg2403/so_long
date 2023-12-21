/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:29 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/21 15:18:14 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_map map)
{
	int	i;

	i = 0;
	free(map.path);
	while (map.map[i])
	{
		free(map.map[i]);
		free(map.points[i]);
		i++;
	}
	free(map.points);
	free(map.map);
}


int	main(int ac, char **av)
{
	t_map	map;
	t_res	res;

	if (ac != 2)
	{
		ft_printf("Error\nMore than one argument!\n");
		exit(1);
	}
	res = get_map(av[1], &map);
	if (res.state)
		exit_errors(res, map);
	generate_map(&map);
	//free_all(map);
	exit (0);
}
