/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:04:15 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/21 14:03:45 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*create_img(t_vars *mlx, int x, int y, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;
	int		corr_x;
	int		corr_y;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	if (!img)
	{
		ft_printf("%s not found", path);
		return (NULL);
	}
	if (img_height != IMG_SIZE)
	{
		corr_x = x * IMG_SIZE + img_height / 2;
		corr_y = y * IMG_SIZE + img_width / 2;
	} 
	else {
		corr_x = x * IMG_SIZE;
		corr_y = y * IMG_SIZE;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, corr_x, corr_y);
	return (img);
}

char	*get_correct_map_image(t_map **map, int x, int y)
{
	t_point	*ptn;

	ptn = &(*map)->points[y][x];
	if ((*ptn).value == WALL)
		return ("./images/wall_50x50.xpm");
	else if ((*ptn).value == PATH)
		return ("./images/ground_50x50.xpm");
	else if ((*ptn).value == PLAYER)
		return ("./images/char.xpm");
	else if ((*ptn).value == EXIT)
		return ("./images/door_50x50.xpm");
	else if ((*ptn).value == ITEM)
		return ("./images/body-1_25x25.xpm");
	else
		return ("./images/wall_50x50.xpm");
}

void	create_correct_image(t_vars *mlx, int x, int y, t_map **map)
{
	t_point	*ptn;

	ptn = &(*map)->points[y][x];
	if ((*ptn).value == PLAYER || (*ptn).value == ITEM)
	{
		create_img(mlx, x, y, "./images/ground_50x50.xpm");
		create_img(mlx, x, y, get_correct_map_image(map, x, y));
	}
	else
		create_img(mlx, x, y, get_correct_map_image(map, x, y));
}

void	generate_map(t_map *map)
{
	t_vars	mlx;
	void	*mlx_ini;
	void	*mlx_win;
	int		i;
	int		j;

	mlx_ini = mlx_init();
	mlx_win = mlx_new_window(mlx_ini, IMG_SIZE * (*map)->width,
			IMG_SIZE * (*map).height, "Game");
	mlx.mlx = mlx_ini;
	mlx.win = mlx_win;
	init_zero(2, &i, &j);
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			//create_img(mlx, j, i, get_correct_map_image(map, j, i));
			create_correct_image(&mlx, j, i, map);
			j++;
		}
		i++;
	}
	//set les binds via les touches du clavier
	config_binds(mlx);
	mlx_loop(mlx_ini);
}