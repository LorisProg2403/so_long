/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:11:42 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 13:03:59 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	visit_point(int x, int y, int items, t_map *map)
{
	t_point	point;

	if (x < 0 || y < 0 || x > (*map).width || y > (*map).height)
		return ;
	point = (*map).points[y][x];
	if (point.value == WALL)
		return ;
	if (point.visited)
		return ;
	if (point.value == ITEM)
		items++;
	if (point.value == EXIT)
		(*map).exit_reached = 1;
	if (items == (*map).items)
		(*map).items_reached = 1;
	point.visited = true;
	(*map).points[y][x] = point;
	visit_point(x + 1, y, items, map);
	visit_point(x - 1, y, items, map);
	visit_point(x, y + 1, items, map);
	visit_point(x, y - 1, items, map);
}

t_res	is_winnable(t_map map)
{
	visit_point(map.spawn.x, map.spawn.y, 0, &map);
	if (!map.exit_reached)
		return (make_res(1, 2, "Can't reach the exit!\n", NULL));
	if (!map.items_reached)
		return (make_res(1, 2, "Can't reach the items!\n", NULL));
	return (make_res(0, 0, NULL, NULL));
}
