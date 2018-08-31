/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:15:57 by cbester           #+#    #+#             */
/*   Updated: 2018/07/17 09:16:04 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int	map_dimensions(char *line, t_datalist **data)
{
	char	*str;
	int		c;
	int		i;
	int		x;

	c = 0;
	i = 7;
	while (line[++i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			x = 0;
			while (ft_isdigit(line[i++]))
				x++;
			if (!(str = ft_strsub(line, --i - x, x)))
				return (0);
			x = ft_atoi(str);
			free(str);
			if (c++ == 0)
				(*data)->map_y = x;
			else
				(*data)->map_x = x;
		}
	}
	return (1);
}

int	piece_dimensions(char *line, t_datalist **data)
{
	char	*str;
	int		c;
	int		i;
	int		x;

	c = 0;
	i = 5;
	while (line[++i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			x = 0;
			while (ft_isdigit(line[i++]))
				x++;
			if (!(str = ft_strsub(line, --i - x, x)))
				return (0);
			x = ft_atoi(str);
			free(str);
			if (c++ == 0)
				(*data)->piece_y = x;
			else
				(*data)->piece_x = x;
		}
	}
	return (1);
}

int	map_reader(t_datalist **data, int fd, char *line)
{
	int	i;

	i = -1;
	if (!map_dimensions(line, data))
		return (0);
	if (!((*data)->map = (char**)malloc(sizeof(char*) * ((*data)->map_y + 1))))
		return (0);
	get_next_line(fd, &line);
	while (i < (*data)->map_y - 1)
	{
		get_next_line(fd, &line);
		(*data)->map[++i] = ft_strsub(line, 4, (*data)->map_x);
	}
	(*data)->map[++i] = NULL;
	return (1);
}

int	piece_reader(t_datalist **data, int fd, char *line)
{
	int	i;

	i = -1;
	if (!piece_dimensions(line, data))
		return (0);
	if (!((*data)->piece = (char**)malloc(sizeof(char*)
					* ((*data)->piece_y + 1))))
		return (0);
	while (i < (*data)->piece_y - 1)
	{
		get_next_line(fd, &line);
		(*data)->piece[++i] = ft_strdup(line);
	}
	(*data)->piece[++i] = NULL;
	return (1);
}

int	data_reader(t_datalist **data, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "Piece"))
		{
			if (!piece_reader(data, fd, line))
			{
				free(line);
				return (0);
			}
			break ;
		}
		else
		{
			if (!map_reader(data, fd, line))
			{
				free(line);
				return (0);
			}
		}
	}
	free(line);
	return (1);
}
