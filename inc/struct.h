/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:38:03 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/28 19:07:37 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"

# define WINDOW_NAME 	"SO_LONG"
# define IMG_SIZE		50

enum e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_counter
{
	int		path;
	int		items;
	int		exit;
	int		spawn;
	int		movements;
}	t_counter;

typedef struct s_img
{
	void		*ptr;
	int			*pixels;
	int			mem;
	int			line_len;
	int			moves;
	int			x;
	int			y;
}	t_img;

typedef struct s_player
{
	t_point		pos;
	bool		is_alive;
	int			item_collected;
	t_img		down;
	t_img		up;
	t_img		left;
	t_img		right;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	char		*line;
}	t_map;


typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_counter	count;
	t_img		floor;
	t_img		wall;
	t_img		items;
	t_img		exit;
	t_img		char_d;
	t_img		char_u;
	t_img		char_l;
	t_img		char_r;
}	t_game;

#endif
