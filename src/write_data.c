/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:13:16 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 20:13:24 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_piece(t_player *player, int i)
{
	char	*line;
	int		h;
	int		w;

	get_next_line(0, &line);
	player->token.height = ft_atoi(&line[6]);
	i = 6;
	while (line[i] != ' ')
		i++;
	player->token.width = ft_atoi(&line[i]);
	player->token.token = (char**)malloc(sizeof(char*) * player->token.height);
	ft_strdel(&line);
	h = -1;
	while (++h < player->token.height)
	{
		player->token.token[h] = (char*)malloc(sizeof(char) *
								player->token.width + 1);
		get_next_line(0, &line);
		i = 0;
		w = 0;
		while (w < player->token.width)
			player->token.token[h][w++] = line[i++];
		player->token.token[h][w] = '\0';
		ft_strdel(&line);
	}
}

void	write_line(t_player *player, const char *line, int h)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (w < player->map.width)
		player->map.map[h][w++] = line[i++];
	player->map.map[h][w] = '\0';
}

void	write_map(t_player *player, int i)
{
	char	*line;
	int		h;

	h = 0;
	while (h < player->map.height)
	{
		get_next_line(0, &line);
		i = 0;
		while (line[i] != '.' && line[i] != 'X' && line[i] != 'O' && line[i])
			i++;
		if (line[i] != '\0')
		{
			write_line(player, &line[i], h);
			h++;
		}
		ft_strdel(&line);
	}
}
