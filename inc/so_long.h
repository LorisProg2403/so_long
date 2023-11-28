/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:29:43 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/28 19:18:24 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include "struct.h"
# include "img_path.h"

// endgame.c
void	endgame(char *msg, t_game *game, enum e_state i);
void	free_map(t_game *game);
void	destroy_image(t_game *game);

#endif
