/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:22:24 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/19 11:47:36 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_zero(int count, ...)
{
	va_list	args;
	int		*curr;
	int		i;

	i = 0;
	va_start(args, count);
	while (i < count)
	{
		curr = va_arg(args, int*);
		*curr = 0;
		i++;
	}
	va_end(args);
}

t_res	make_res(bool state, int code, char *msg, void *data)
{
	t_res	res;

	res.state = state;
	res.code = code;
	res.data = data;
	res.msg = msg;
	return (res);
}
