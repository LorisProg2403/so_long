/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:58:03 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/20 12:40:27 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*static void	free_map_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

static void	free_points(t_map map)
{
	int	i;

	i = 0;
	while (i <= map.height)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
}*/

void	exit_errors(t_res res, t_map map)
{
	ft_printf("Error\n");
	ft_printf(res.msg);
	(void)map;
	/*if (res.code == MAP_ERROR)
	{
		free(map.path);
		free_map_map(map);
	}
	if (res.code == PATH_ERROR)
	{
		free(map.path);
		free_map_map(map);
		free_points(map);
	}*/
	exit (1);
}
