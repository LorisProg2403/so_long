/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:06:35 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 14:34:50 by lgaume           ###   ########.fr       */
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
	printf("%d\n", img_height);
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

char	*get_correct_map_image(t_map *map, int x, int y)
{
	t_point	*ptn;

	ptn = &(*map).points[y][x];
	if ((*ptn).value == WALL)
		return (WALL_IMG_PATH);
	else if ((*ptn).value == PATH)
		return (PATH_IMG_PATH);
	else if ((*ptn).value == SPAWN)
		return (PLAYER_IMG_PATH);
	else if ((*ptn).value == EXIT)
		return (EXIT_IMG_PATH);
	else
		return (ITEM_IMG_PATH);
}

void	create_correct_image(t_vars *mlx, int x, int y, t_map *map)
{
	t_point	*ptn;

	ptn = &(*map).points[y][x];
	if ((*ptn).value == SPAWN || (*ptn).value == ITEM)
	{
		create_img(mlx, x, y, PATH_IMG_PATH);
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
	mlx_win = mlx_new_window(mlx_ini, IMG_SIZE * ((*map).width + 1),
			IMG_SIZE * ((*map).height + 1), "Game");
	mlx.mlx = mlx_ini;
	mlx.win = mlx_win;
	set_zero(2, &i, &j);
	while (i <= (*map).height)
	{
		j = 0;
		while (j <= (*map).width)
		{
			//create_img(mlx, j, i, get_correct_map_image(map, j, i));
			create_correct_image(&mlx, j, i, map);
			j++;
		}
		i++;
	}
	//set les binds via les touches du clavier
	//config_binds(mlx);
	mlx_loop(mlx_ini);
}
