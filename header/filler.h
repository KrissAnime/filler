/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 06:35:16 by cbester           #+#    #+#             */
/*   Updated: 2018/07/19 13:38:25 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_datalist
{
	char		me;
	char		op;
	char		**piece;
	char		**map;
	int			bgx;
	int			bgy;
	int			edx;
	int			edy;
	int			clx;
	int			cly;
	int			piece_x;
	int			piece_y;
	int			map_x;
	int			map_y;
	int			opx;
	int			opy;
	int			plex;
	int			pley;
}				t_datalist;

void			free_data(t_datalist **data);
void			newtrim(t_datalist **data);
void			create_data(t_datalist **data);
void			check_score(t_datalist **data);

int				player_data(t_datalist **data, char *line);
int				strategy(t_datalist **data);

int				data_reader(t_datalist **data, int fd);
int				map_dimensions(char *line, t_datalist **data);
int				piece_dimensions(char *line, t_datalist **data);
int				map_reader(t_datalist **data, int fd, char *line);
int				piece_reader(t_datalist **data, int fd, char *line);

int				isval(int cy, int y, int x, t_datalist **data);
int				isval_alt(int cy, int y, int x, t_datalist **data);

int				nojunk(int y, int x, t_datalist **data);

int				place(t_datalist **data, int x, int y);
int				place_alt(t_datalist **data, int x, int y);

int				tokenfit(int y, int x, t_datalist **data);
int				tokenfit_alt(int y, int x, t_datalist **data);

int				distance(int y, int x, t_datalist **data);
int				distance_alt(int y, int x, t_datalist **data);

int				closest(int y, int x, t_datalist **data);
int				closest_alt(int y, int x, t_datalist **data);

#endif
