/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:01:04 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 14:35:06 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

// Images path
# define WALL_IMG_PATH "./img/wall.xpm"
# define PATH_IMG_PATH "./img/grass.xpm"
# define EXIT_IMG_PATH "./img/exit.xpm"
# define ITEM_IMG_PATH "./img/apple.xpm"
# define PLAYER_IMG_PATH "./img/link_sprites/up_1_1.xpm"

// Error code
# define MALLOC_ERROR 1
# define PATH_ERROR 2
# define MAP_ERROR 3

// Data
# define IMG_SIZE 32

// MAP CHARACTERS
# define WALL '1'
# define PATH '0'
# define ITEM 'C'
# define EXIT 'E'
# define SPAWN 'P'

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_counter
{
	int 	exit;
	int 	items;
	int 	spawn;
}	t_counter;

typedef struct s_res
{
	bool	state;
	int 	code;
	void	*data;
	char	*msg;
}	t_res;

typedef struct s_point
{
    char	value;
    int		x;
    int		y;
    bool	visited;
}	t_point;

typedef struct s_map
{
    char	**map;
	char	*path;
    int		height;
    int		width;
    int		items;
	bool	exit_reached;
	bool	items_reached;
	t_point spawn;
	t_point exit;
	t_point **points;
}	t_map;

//Functions
t_res	get_map(char *s, t_map *map);
t_res 	check_map(t_map map);

t_point new_pt(int x, int y, char value);
void	create_tab_pt(t_map *map, int y, int x);

t_res	is_winnable(t_map map);

t_res	make_res(bool state, int code, char *msg, void *data);

void	set_zero(int count, ...);
void	exit_errors(t_res res, t_map map);

void	generate_map(t_map *map);
#endif
