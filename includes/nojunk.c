/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nojunk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:46:39 by cbester           #+#    #+#             */
/*   Updated: 2018/07/17 09:53:04 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int	nojunk(int y, int x, t_datalist **data)
{
	int cy;
	int	cx;
	int	ty;
	int	tx;

	cy = -1;
	tx = (*data)->bgx;
	ty = (*data)->bgy;
	while (++cy < (*data)->edy)
	{
		cx = -1;
		while (++cx < (*data)->edx)
		{
			if ((*data)->map[y + cy][x + cx] != (*data)->me
					&& (*data)->map[y + cy][x + cx] != (*data)->me + 32
					&& (*data)->map[y + cy][x + cx] != (*data)->op
					&& (*data)->map[y + cy][x + cx] != (*data)->op + 32
					&& (*data)->map[y + cy][x + cx] != '.'
					&& (*data)->piece[cy + ty][cx + tx] == '*')
				return (0);
		}
	}
	return (1);
}
