/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:48:48 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 12:08:50 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_tab_pt(t_map *map, int y, int x)
{
	int	i;
	int	j;

	(*map).width = x - 1;
	(*map).height = y - 1;
	(*map).points = malloc(sizeof(t_point *) * y);
	i = 0;
	while (i < y)
	{
		j = 0;
		(*map).points[i] = malloc(sizeof(t_point) * x);
		while (j < x)
		{
			(*map).points[i][j] = new_pt(j, i, (*map).map[i][j]);
			j++;
		}
		i++;
	}
}

t_point	new_pt(int x, int y, char value)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.value = value;
	p.visited = false;
	return (p);
}
