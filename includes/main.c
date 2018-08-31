/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:19:27 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 11:46:53 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	co_od(t_datalist **data)
{
	ft_putnbr((*data)->pley);
	ft_putchar(' ');
	ft_putnbr((*data)->plex);
	ft_putchar('\n');
}

int		play(t_datalist **data)
{
	if (strategy(data))
		return (place(data, -1, -1));
	return (place_alt(data, (*data)->map_x, (*data)->map_x));
}

int		main(void)
{
	t_datalist	*data;
	char		*line;

	line = NULL;
	data = (t_datalist*)malloc(sizeof(t_datalist));
	get_next_line(0, &line);
	player_data(&data, line);
	free(line);
	while (1)
	{
		if ((!data_reader(&data, 0)))
			return (1);
		newtrim(&data);
		if (!play(&data))
			break ;
		free_data(&data);
		co_od(&data);
	}
	check_score(&data);
	ft_putstr("0 0\n");
	free(data);
	return (0);
}
