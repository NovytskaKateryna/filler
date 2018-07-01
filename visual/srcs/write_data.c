/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:30:32 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:32:43 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	write_piece(t_turn *turn, int x, int y)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	turn->token_height = ft_atoi(&line[6]);
	i = 6;
	while (line[i] != ' ')
		i++;
	turn->token_width = ft_atoi(&line[i]);
	turn->token = (char**)malloc(sizeof(char*) * turn->token_height);
	ft_strdel(&line);
	while (++y < turn->token_height)
	{
		get_next_line(0, &line);
		turn->token[y] = (char*)malloc(sizeof(char) * turn->token_width + 1);
		i = -1;
		x = 0;
		while (line[++i])
			turn->token[y][x++] = line[i];
		turn->token[y][x] = '\0';
		ft_strdel(&line);
	}
}

void	write_line(t_vis *v, t_turn *turn, const char *line, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (x < v->map_width)
		turn->map[y][x++] = line[i++];
	turn->map[y][x] = '\0';
}

void	write_map(t_vis *v, t_turn *turn, int x, int y)
{
	char *line;

	turn->map = (char**)malloc(sizeof(char*) * v->map_height);
	while (x < v->map_height)
		turn->map[x++] = (char*)malloc(sizeof(char) * v->map_width + 1);
	while (++y < v->map_height)
	{
		get_next_line(0, &line);
		x = 0;
		while (line[x] != '.' && line[x] != 'x' &&
			line[x] != 'o' && line[x] != 'X' && line[x] != 'O' && line[x])
			x++;
		if (line[x] != '\0')
			write_line(v, turn, &line[x], y);
		ft_strdel(&line);
	}
}
