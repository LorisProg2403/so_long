/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:17:48 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/21 15:18:20 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_map	init_map(char *s)
{
	t_map	out;
	int		i;
	int		fd;
	char	*line;

	out.path = ft_strjoin("maps/", s);
	i = 0;
	fd = open(out.path, O_RDONLY);
	if (fd < 0)
		exit_errors(make_res(1, 0, "Can't find file!\n", NULL), out);
	out.map = malloc(sizeof(char *) * 120);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		out.map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	(void)i;
	return (out);
}

static void	set_map(t_map *map)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	items = 0;
	while ((*map).map[i])
	{
		j = 0;
		while ((*map).map[i][j])
		{
			if ((*map).map[i][j] == ITEM)
				items++;
			if ((*map).map[i][j] == PLAYER)
				(*map).player = new_pt(j, i, 'P');
			if ((*map).map[i][j] == EXIT)
				(*map).exit = new_pt(j, i, 'E');
			j++;
		}
		i++;
	}
	(*map).items = items;
	create_tab_pt(map, i, j);
}

t_res	get_map(char *s, t_map *map)
{
	t_res	res;

	*map = init_map(s);
	res = check_map(*map);
	if (res.state)
		return (res);
	set_map(map);
	if (res.state)
		return (res);
	map->items_reached = false;
	map->exit_reached = false;
	map->moves = 0;
	res = is_winnable(*map);
	return (res);
}
