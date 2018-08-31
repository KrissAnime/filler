/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:29:38 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 10:34:39 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	check_score(t_datalist **data)
{
	int	x;
	int	y;
	int	me;
	int	en;

	y = -1;
	me = 0;
	en = 0;
	while (++y < (*data)->map_y)
	{
		x = -1;
		while (++x < (*data)->map_x)
		{
			(me += (*data)->map[y][x] == (*data)->me ? 1 : 0);
			(en += (*data)->map[y][x] == (*data)->op ? 1 : 0);
		}
	}
	if (me < en)
		ft_putstr_fd("BETTER LUCK NEXT TIME...\n", 2);
	if (me > en)
		ft_putstr_fd("ARE YOU NOT ENTERTAINED?!\n", 2);
	if (en == me)
		ft_putstr_fd("A DRAW, SERIOUSLY???\n", 2);
}
