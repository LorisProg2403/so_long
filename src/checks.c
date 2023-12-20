/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:46 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 12:03:37 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	has_everything(t_map map)
{
	t_point		p;
	t_counter	c;

	set_zero(4, &p.x, &c.exit, &c.spawn, &c.items);
	while (map.map[p.x])
	{
		p.y = 0;
		while (map.map[p.x][p.y])
		{
			if (map.map[p.x][p.y] == ITEM)
				c.items++;
			else if (map.map[p.x][p.y] == EXIT)
				c.exit++;
			else if (map.map[p.x][p.y] == SPAWN)
				c.spawn++;
			else if (map.map[p.x][p.y] != WALL && map.map[p.x][p.y] != PATH)
				return (false);
			p.y++;
		}
		p.x++;
	}
	if (c.items >= 1 && c.exit == 1 && c.spawn == 1)
		return (true);
	return (false);
}

static bool	map_is_rectangle(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (false);
		i++;
	}
	if (i == len)
		return (false);
	return (true);
}

static bool	surrounded_by_wall(char **map)
{
	int	i;
	int	w;
	int	h;

	w = ft_strlen(map[0]);
	h = 0;
	while (map[h])
		h++;
	i = 0;
	while (map[0][i] == WALL && map[h - 1][i] == WALL)
		i++;
	if (i != w)
		return (false);
	i = 0;
	while (map[i] && map[i][0] == WALL && map[i][w - 1] == WALL)
		i++;
	if (i != h)
		return (false);
	return (true);
}

t_res	check_map(t_map map)
{
	if (!has_everything(map))
		return (make_res(1, 3, "Unplayble map!\n", NULL));
	printf("everything => ok\n");
	if (!map_is_rectangle(map.map))
		return (make_res(1, 3, "Map should be a rectanlge!\n", NULL));
	printf("rectangle => ok\n");
	if (!surrounded_by_wall(map.map))
		return (make_res(1, 3, "Map should be surrounded by wall!\n", NULL));
	printf("surrounded => ok\n");
	return (make_res(0, 0, NULL, NULL));
}
