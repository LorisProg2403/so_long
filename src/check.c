/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:09 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 18:35:37 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*static void	check_map(char ***map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = (int)ft_strlen(*map[0]);
	while (*map[i])
	{
		if ((int)ft_strlen(*map[i]) != len)
			error_and_free("Wrong size in the map", *map);
		j = 0;
		while (*map[i][j])
		{
			if (*map[i][j] != '0' || *map[i][j] != '1' || *map[i][j] != 'P'
				||*map[i][j] != 'C' || *map[i][j] != 'E' || *map[i][j] != 'D')
				error_and_free("Wrong characters in the map", *map);
			j++;
		}
		i++;
	}
	if (i >= len)
		error_and_free("Map is not a rectangle", *map);
}*/

static void	get_map(int fd, char ***map)
{
	int	i;

	i = 0;
	(void)fd;
	while (1)
	{
		(*map)[i] = get_next_line(1);
		if (!(*map)[i])
			break ;
		i++;
	}
}

void	check_args(int ac, char **av, char ***map)
{
	int		fd;
	int		len;
	char	*format;

	if (ac != 2)
		handle_errors("Wrong number of arguments!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		handle_errors("File not found!");
	len = ft_strlen(av[1]);
	format = ft_substr(av[1], len - 4, 4);
	if (ft_strcmp(format, ".ber"))
		handle_errors("Invalid file type, use .ber!");
	get_map(fd, map);
	//check_map(map);
}
