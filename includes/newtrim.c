/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:57:13 by cbester           #+#    #+#             */
/*   Updated: 2018/07/16 06:38:17 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static int	isempty(int x, int y, char **piece)
{
	while (piece[y][x] != '\0')
	{
		if (piece[y][x] == '*')
			return (0);
		x++;
	}
	return (1);
}

static void	ytrim(t_datalist **data)
{
	int	y;

	y = 0;
	(*data)->bgy = 0;
	(*data)->edy = (*data)->piece_y;
	while (isempty(0, y++, (*data)->piece))
		(*data)->bgy++;
	y = (*data)->piece_y - 1;
	while (isempty(0, y--, (*data)->piece))
		(*data)->edy--;
	(*data)->edy = (*data)->edy - (*data)->bgy;
}

void		newtrim(t_datalist **data)
{
	int	x;
	int	y;

	(*data)->edx = 0;
	(*data)->bgx = (*data)->piece_x;
	y = -1;
	while (++y < (*data)->piece_y)
	{
		x = -1;
		while (++x < (*data)->piece_x)
		{
			if ((*data)->piece[y][x] == '*')
			{
				if ((*data)->edx < x)
					(*data)->edx = x;
				if ((*data)->bgx > x)
					(*data)->bgx = x;
			}
		}
	}
	(*data)->edx = (*data)->edx - (*data)->bgx + 1;
	ytrim(data);
}
