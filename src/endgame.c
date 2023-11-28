/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:48:30 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/28 19:18:20 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.ptr);
	mlx_destroy_image(game->mlx_ptr, game->items.ptr);
	mlx_destroy_image(game->mlx_ptr, game->char_d.ptr);
	mlx_destroy_image(game->mlx_ptr, game->char_u.ptr);
	mlx_destroy_image(game->mlx_ptr, game->char_l.ptr);
	mlx_destroy_image(game->mlx_ptr, game->char_r.ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//mlx_destroy_display(game->mlx_ptr);
	free_map(game);
	free(game->mlx_ptr);
}

void	free_map(t_game *game)
{
	while (game->map.height > 0)
	{
		free(game->map.map[game->map.height - 1]);
		game->map.height--;
	}
	free(game->map.map);
}

void	endgame(char *msg, t_game *game, enum e_state i)
{
	if (i == event_ending || i == game_over)
	{
		ft_printf("%s\n", msg);
		destroy_image(game);
		exit(0);
	}
	else if (i == error)
	{
		ft_printf(RED"Error\n%s\n"ENDC, msg);
		exit(1);
	}
	else if (i == file_error)
	{
		ft_printf(RED"Error\n%s\n", msg);
		exit(1);
	}
	ft_printf(RED"Error\n%s\n", msg);
	destroy_image(game);
	exit(1);
}
