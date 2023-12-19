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

static void	set_map(t_map *map)
{
	int i;
	int j;
	int items;

	i = 0;
	items = 0;
	while ((*map).map[i])
	{
		j = 0;
		while ((*map).map[i][j])
		{
			if ((*map).map[i][j] == ITEM)
				items++;
			if ((*map).map[i][j] == SPAWN)
				(*map).spawn = new_pt(j, i, 'P');
			if ((*map).map[i][j] == EXIT)
				(*map).exit = new_pt(j, i, 'E');
			j++;
		}
		i++;
	}
	(*map).items = items;
	create_tab_pt(map, i, j);
}

static t_map init_map(char *s)
{
	t_map 	out;
	int		i;
	int 	fd;
	char 	*line;

	out.path = ft_strjoin("maps/", s);
	i = 0;
	fd = open(out.path, O_RDONLY);
	if (fd < 0)
		exit_errors(make_res(1, 0, "Can't find file!\n", NULL), out);
	out.map = malloc(sizeof(char *) * 20);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		out.map[i] = ft_strtrim(line,"\n");
		free(line);
		i++;
	}
	(void)i;
	return (out);
}

void	print_points(t_map map)
{
	printf("\n\n=====POINTS_TEST====\n\n");
	printf("Exit => (%d;%d)\n", map.exit.x, map.exit.y);
	printf("Spawn => (%d;%d)\n", map.spawn.x, map.spawn.y);
	printf("Exit => %c\n", map.exit.value);
	printf("Spawn => %c\n", map.spawn.value);
	printf("Items => %d\n\n", map.items);
	int i = 0;
	while (i <= map.height)
	{
		int j = 0;
		while (j <= map.width)
		{
			printf("%c", map.points[i][j].value);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_map 	map;
	t_res	res;

    if (ac != 2)
	{
		ft_printf("Error\nMore than one argument!\n");
		exit(1);
	}
	map = init_map(av[1]);
	res = check_map(map);
	if (res.state)
		exit_errors(res, map);
	printf("map => ok\n");
	set_map(&map);
	print_points(map);
	int i = 0;
	free(map.path);
	while (map.map[i])
	{
		free(map.map[i]);
		free(map.points[i]);
		i++;
	}
	free(map.points);
	free(map.map);
	return (0);
}
