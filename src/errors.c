/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:17:04 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/27 19:12:42 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_and_free(char *msg, char **str)
{
	ft_free_ptrstr(str);
	ft_printf("Error\n%s\n", msg);
	exit(1);
}
