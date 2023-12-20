/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:29 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 14:08:37 by lgaume           ###   ########.fr       */
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
	printf("winnable => ok\n");
	print_points(map);
	generate_map(&map);
	free_all(map);
	return (0);
}
