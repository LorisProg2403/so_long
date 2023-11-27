/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:29 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 21:41:45 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	map = check_args(ac, av);
	ft_printf("Everything went well\n");
	ft_free_ptrstr(map);
}
