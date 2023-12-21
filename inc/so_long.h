/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:01:04 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/21 14:06:47 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

// Keys
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_ESC 53

// Images path
# define WALL_IMG_PATH "./img/crash/wall.xpm"
# define PATH_IMG_PATH "./img/crash/grass.xpm"
# define EXIT_IMG_PATH "./img/crash/exit.xpm"
# define ITEM_IMG_PATH "./img/crash/apple.xpm"
# define PLAYER_IMG_PATH "./img/crash/player.xpm"

// Error code
# define MALLOC_ERROR 1
# define PATH_ERROR 2
# define MAP_ERROR 3

// Data
# define IMG_SIZE 50

// MAP CHARACTERS
# define WALL '1'
# define PATH '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'


typedef struct s_map t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_vars;

typedef struct s_counter
{
	int		exit;
	int		items;
	int		spawn;
}	t_counter;

typedef struct s_res
{
	bool	state;
	int		code;
	void	*data;
	char	*msg;
}	t_res;

typedef struct s_img
{
	void	*img;
	t_vars	mlx;
}	t_img;

typedef struct s_point
{
	char	value;
	int		x;
	int		y;
	bool	visited;
	t_img	img;
	bool	has_image;
}	t_point;

typedef struct s_map
{
	char	**map;
	char	*path;
	int		height;
	int		width;
	int		items;
	int		moves;
	bool	exit_reached;
	bool	items_reached;
	t_point	player;
	t_point	exit;
	t_point	**points;
}	t_map;


//Functions
t_res	get_map(char *s, t_map *map);
t_res	check_map(t_map map);

int	config_bind(int key, t_vars *mlx);

t_point	new_pt(int x, int y, char value);
void	create_tab_pt(t_map *map, int y, int x);

t_res	is_winnable(t_map map);

t_res	make_res(bool state, int code, char *msg, void *data);

void	set_zero(int count, ...);
void	exit_errors(t_res res, t_map map);

void	generate_map(t_map *map);
void	create_correct_image(t_vars mlx, int x, int y, t_map *map);
char	*get_correct_map_image(t_map *map, int x, int y, char c);
void	*create_img(t_vars mlx, int x, int y, char *path);

//void	move_right(t_vars data);
#endif
