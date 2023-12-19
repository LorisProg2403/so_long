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
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	out.map = malloc(sizeof(char *) * 20);
	while (1)
	{
		//ft_realloc(out.map, sizeof(char *) * (i + 1));
		line = get_next_line(fd);
		if (!line)
			break;
		//printf("%s\n", ft_strtrim(line,"\n"));
		out.map[i] = ft_strtrim(line,"\n");
		free(line);
		i++;
	}
	(void)i;
	return (out);
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
	int i = 0;
	free(map.path);
	while (map.map[i])
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	return (0);
}
