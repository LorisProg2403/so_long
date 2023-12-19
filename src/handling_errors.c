/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:58:03 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/18 16:58:05 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_map_map(t_map map)
{
	int i;

	i = 0;
	while (map.map[i])
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

void	exit_errors(t_res res, t_map map)
{
	ft_printf("Error\n");
	ft_printf(res.msg);
	if (res.code == MAP_ERROR)
	{
		free(map.path);
		free_map_map(map);
	}
	exit (1);
}
