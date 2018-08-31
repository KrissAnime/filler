/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:50:51 by cbester           #+#    #+#             */
/*   Updated: 2018/07/17 09:53:54 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int	isval_alt(int cy, int y, int x, t_datalist **data)
{
	int	cx;
	int	ty;
	int	tx;
	int	count;

	count = 0;
	tx = (*data)->bgx;
	ty = (*data)->bgy;
	while (++cy < (*data)->edy)
	{
		cx = -1;
		while (++cx < (*data)->edx)
		{
			if (((*data)->map[y + cy][x + cx] == (*data)->me
					|| (*data)->map[y + cy][x + cx] == (*data)->me + 32)
					&& (*data)->piece[cy + ty][cx + tx] == '*')
				count++;
			else if (((*data)->map[y + cy][x + cx] == (*data)->op
					|| (*data)->map[y + cy][x + cx] == (*data)->op + 32)
					&& (*data)->piece[cy + ty][cx + tx] == '*')
				return (0);
		}
	}
	return ((count == 1) ? 1 : 0);
}

int	tokenfit_alt(int y, int x, t_datalist **data)
{
	if (y + (*data)->edy > (*data)->map_y)
		return (0);
	if (x + (*data)->edx > (*data)->map_x)
		return (0);
	if (!nojunk(y, x, data))
		return (0);
	return (isval_alt(-1, y, x, data));
}

int	distance_alt(int y, int x, t_datalist **data)
{
	int	fdist;
	int	py;
	int	px;
	int	distx;
	int	disty;

	fdist = 0;
	py = -1;
	while (++py < (*data)->edy)
	{
		px = -1;
		while (++px < (*data)->edx)
		{
			if ((*data)->piece[py][px] == '*')
			{
				distx = ft_abs(ft_abs((x - (*data)->opx)) - px);
				disty = ft_abs(ft_abs((y - (*data)->opy)) - py);
				fdist = fdist + ((distx * distx) / 2) + ((disty * disty) / 2);
			}
		}
	}
	return (fdist);
}

int	closest_alt(int y, int x, t_datalist **data)
{
	int	close;
	int	other;
	int	y2;
	int	x2;

	y2 = (*data)->map_y;
	other = 2147483647;
	while (--y2 >= 0)
	{
		x2 = (*data)->map_x;
		while (--x2 >= 0)
		{
			if ((*data)->map[y2][x2] == (*data)->op
					|| (*data)->map[y2][x2] == (*data)->op + 32)
			{
				(*data)->opx = x2;
				(*data)->opy = y2;
				close = distance_alt(y, x, data);
				if (close < other)
					other = close;
			}
		}
	}
	return (other);
}

int	place_alt(t_datalist **data, int x, int y)
{
	int	play;
	int	close;
	int	closer;

	play = 0;
	closer = 2147483647;
	while (--y >= 0)
	{
		x = (*data)->map_x;
		while (--x >= 0)
		{
			if (tokenfit_alt(y, x, data))
			{
				close = closest_alt(y, x, data);
				if (close < closer)
				{
					play = 1;
					(*data)->plex = x - (*data)->bgx;
					(*data)->pley = y - (*data)->bgy;
					closer = close;
				}
			}
		}
	}
	return ((play == 1 ? 1 : 0));
}
