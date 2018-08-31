/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:09:50 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 11:46:19 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int	strategy(t_datalist **data)
{
	int	x;
	int	y;

	y = -1;
	(*data)->clx = 0;
	(*data)->cly = 0;
	while (++y < (*data)->map_y)
	{
		x = -1;
		while (++x < (*data)->map_x)
		{
			if ((*data)->map[y][x] == (*data)->me)
			{
				if ((*data)->clx < x)
					(*data)->clx = x;
				if ((*data)->cly < y)
					(*data)->cly = y;
			}
		}
	}
	if (y < (*data)->map_y / 2)
		return (1);
	return (0);
}
