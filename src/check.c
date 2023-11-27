/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:09 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 15:22:49 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**check_map(int fd)
{
	
}

void	check_args(int ac, char **av)
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
		handle_errors("Invalid file type, use .ber!");
	map = check_map(fd);
}