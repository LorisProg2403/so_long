/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:29:43 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 19:12:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"

char	**check_args(int ac, char **av);
void	error_and_free(char *msg, char **str);

#endif
