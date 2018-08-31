/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:12:09 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 10:17:30 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int	player_data(t_datalist **data, char *line)
{
	if (line[10] == '1')
	{
		(*data)->me = 'O';
		(*data)->op = 'X';
		return (1);
	}
	if (line[10] == '2')
	{
		(*data)->me = 'X';
		(*data)->op = 'O';
		return (1);
	}
	free(line);
	return (0);
}
