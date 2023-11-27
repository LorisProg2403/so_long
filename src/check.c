/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:09 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 22:00:31 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	map_char(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == 'P')
		return (true);
	if (c == 'C')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'D')
		return (true);
	if (c == '\n')
		return (true);
	return (false);
}

static void	check_map(char **map)
{
	int	i;
	int	j;
	int	len;

	if (!map[0][0])
		error_and_free("Map couldn't be create", map);
	i = 0;
	len = (int)ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			error_and_free("Wrong size in the map", map);
		j = 0;
		while (map[i][j])
		{
			if (!map_char(map[i][j]))
				error_and_free("Wrong characters in the map", map);
			j++;
		}
		i++;
	}
	if (i >= len)
		error_and_free("Map is not a rectangle", map);
}

static char	**get_map(int fd)
{
	int		i;
	char	**map;

	i = 0;
	map = NULL;
	while (1)
	{
		map = ft_realloc(map, sizeof(char *) * (size_t)(i + 2));
		if (!map)
			return (NULL);
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			map[i + 1] = NULL;
			break ;
		}
		i++;
	}
	return (map);
}

char	**check_args(int ac, char **av)
{
	int		fd;
	int		len;
	char	*format;
	char	**map;

	if (ac != 2)
		handle_errors("Wrong number of arguments!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		handle_errors("File not found!");
	len = ft_strlen(av[1]);
	format = ft_substr(av[1], len - 4, 4);
	if (ft_strcmp(format, ".ber"))
	{
		handle_errors("Invalid file type, use .ber!");
		free(format);
	}
	free(format);
	map = get_map(fd);
	check_map(map);
	check_valid_map(map);
	return (map);
}
