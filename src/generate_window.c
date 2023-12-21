/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:06:35 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/21 14:03:45 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_corr(t_point *c, t_point p, int width, int height)
{
	if (height == IMG_SIZE / 2)
	{
		(*c).x = p.x * IMG_SIZE + height / 2;
		(*c).y = p.y * IMG_SIZE + width / 2;
	}
	else if (width == 29)
	{
		(*c).x = p.x * IMG_SIZE + 11;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	else if (height == 45)
	{
		(*c).x = p.x * IMG_SIZE + 3;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	else
	{
		(*c).x = p.x * IMG_SIZE;
		(*c).y = p.y * IMG_SIZE;
	}
}

void	*create_img(t_vars mlx, int x, int y, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;
	t_point	corr;

	img = mlx_xpm_file_to_image(mlx.mlx, path, &img_width, &img_height);
	if (!img)
	{
		ft_printf("%s not found", path);
		return (NULL);
	}
	get_corr(&corr, new_pt(x, y, '\0'), img_width, img_height);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, corr.x, corr.y);
	return (img);
}

char	*get_correct_map_image(t_map *map, int x, int y, char c)
{
	t_point	*ptn;

	if (c)
	{
		if (c == WALL)
		return (WALL_IMG_PATH);
	else if (c == PATH)
		return (PATH_IMG_PATH);
	else if (c == PLAYER)
		return (PLAYER_IMG_PATH);
	else if (c == EXIT)
		return (EXIT_IMG_PATH);
	else
		return (ITEM_IMG_PATH);
	}
	ptn = &(*map).points[y][x];
	if ((*ptn).value == WALL)
		return (WALL_IMG_PATH);
	else if ((*ptn).value == PATH)
		return (PATH_IMG_PATH);
	else if ((*ptn).value == PLAYER)
		return (PLAYER_IMG_PATH);
	else if ((*ptn).value == EXIT)
		return (EXIT_IMG_PATH);
	else
		return (ITEM_IMG_PATH);
}

void	create_correct_image(t_vars mlx, int x, int y, t_map *map)
{
	t_point	pts;

	pts = (*map).points[y][x];
	if (pts.value == PLAYER || pts.value == ITEM || pts.value == EXIT)
	{
		create_img(mlx, x, y, PATH_IMG_PATH);
		pts.img.img = create_img(mlx, x, y, get_correct_map_image(map, x, y, '\0'));
		pts.has_image = true;
		pts.img.mlx = mlx;
	}
	else
		create_img(mlx, x, y, get_correct_map_image(map, x, y, '\0'));
	(*map).points[y][x] = pts;
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
			IMG_SIZE * ((*map).height + 1), "SO_LONG");
	mlx.mlx = mlx_ini;
	mlx.win = mlx_win;
	mlx.map = map;
	i = 0;
	while (i <= (*map).height)
	{
		j = 0;
		while (j <= (*map).width)
		{
			create_correct_image(mlx, j, i, map);
			j++;
		}
		i++;
	}
	mlx_key_hook(mlx.win, config_bind, &mlx);
	mlx_loop(mlx_ini);
}