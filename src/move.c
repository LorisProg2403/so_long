/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:23:14 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/21 15:31:36 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	has_access(t_vars data, t_point pos, int add_x, int add_y)
{
	if (data.map->points[pos.y + add_y][pos.x + add_x].value == WALL)
		return (0);
	if (data.map->points[pos.y + add_y][pos.x + add_x].value == EXIT)
	{
		if (data.map->items)
			return (0);
		else
			exit(0);
	}
	return (1);
}

void	move(t_vars data, int add_x, int add_y)
{
	t_point pos;
	
	pos = data.map->player;
	if (!has_access(data,pos, add_x, add_y))
		return ;
	data.map->moves++;
	ft_printf("%d moves\n", data.map->moves);
	//create_img(data, IMG_SIZE * (data.map->width / 2) + 50, IMG_SIZE * (data.map->height + 1),BLACK_IMG_PATH);
	create_img(data, (data.map->width / 2) + 1, data.map->height + 1,BLACK_IMG_PATH);
	mlx_string_put(data.mlx, data.win,
	   IMG_SIZE * (data.map->width / 2) + 60,
	   IMG_SIZE * (data.map->height + 2) - 25,255 ,
		 ft_itoa(data.map->moves));
	if (data.map->points[pos.y + add_y][pos.x + add_x].value == ITEM)
	{
		data.map->items--;
		data.map->points[pos.y + add_y][pos.x + add_x].value = PATH;
		create_img(data, pos.x + add_x, pos.y + add_y,PATH_IMG_PATH);
	}
	create_img(data, pos.x, pos.y,PATH_IMG_PATH);
	create_img(data, pos.x + add_x, pos.y + add_y,PLAYER_IMG_PATH);
	data.map->player.x += add_x;
	data.map->player.y += add_y;
}

int	config_bind(int key, t_vars *mlx)
{
	if (key == KEY_Q || key == KEY_ESC)
		exit(0);
	if (key == KEY_W)
		move(*mlx, 0, -1);
	if (key == KEY_A)
		move(*mlx, -1, 0);
	if (key == KEY_S)
		move(*mlx, 0, 1);
	if (key == KEY_D)
		move(*mlx, 1, 0);
	return (0);
}