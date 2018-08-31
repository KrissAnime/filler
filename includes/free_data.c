/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:10:13 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 10:17:50 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	free_data(t_datalist **data)
{
	int	y;

	y = 0;
	while ((*data)->map[y])
		free((*data)->map[y++]);
	free((*data)->map);
	y = 0;
	while ((*data)->piece[y])
		free((*data)->piece[y++]);
	free((*data)->piece);
}
