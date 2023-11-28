/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:23:03 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/28 12:37:49 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	width_of_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static bool	wall_all_around(char **map)
{
	int	i;
	int	max_len;
	int	width_len;

	i = 0;
	max_len = ft_strlen(map[0]);
	width_len = width_of_map(map);
	while (i < max_len - 1)
	{
		if (map[0][i] != '1')
			return (false);
		if (map[width_len - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < width_len)
	{
		if (map[i][0] != '1')
			return (false);
		if (map[i][max_len - 2] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	only_one(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				n++;
			j++;
		}
		i++;
	}
	if (n != 1)
		return (false);
	return (true);
}

static bool	at_least_one(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	valid_map(char **map)
{
	if (!wall_all_around(map))
		error_and_free("The map is not surrounded by wall!", map);
	if (!only_one(map, 'P'))
		error_and_free("There must be ONE player", map);
	if (!at_least_one(map, 'C'))
		error_and_free("There must be at least one collectable", map);
	if (!only_one(map, 'E'))
		error_and_free("There must be ONE exit", map);
}
