/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:37:40 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/27 13:18:46 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	delete_map(t_player *player, char **map)
{
	int	n;

	n = -1;
	if (map)
	{
		while (++n < player->map.height)
			ft_strdel(&map[n]);
		free(map);
	}
}

void	delete_token(t_player *player)
{
	int	n;

	n = -1;
	if (player->token.token)
	{
		while (++n < player->token.height)
			ft_strdel(&player->token.token[n]);
		free(player->token.token);
	}
}

void	reset(t_player *player)
{
	player->distance_to_me = 1000;
	player->distance_to_enemy = 1000;
	player->score = -1;
	player->placed = 0;
	player->result[X] = 0;
	player->result[Y] = 0;
	player->op_pos[X] = 0;
	player->op_pos[Y] = 0;
	player->op_close[X] = -1;
	player->op_close[Y] = -1;
	player->up_left = 0;
	player->up_right = 0;
	player->down_left = 0;
	player->down_right = 0;
}

void	get_player_num(t_player *player, char num)
{
	if (num == '1')
	{
		player->my_num = 'O';
		player->op_num = 'X';
	}
	else if (num == '2')
	{
		player->my_num = 'X';
		player->op_num = 'O';
	}
}

void	get_info(t_player *player, char *line)
{
	int	i;

	get_next_line(0, &line);
	get_player_num(player, line[10]);
	ft_strdel(&line);
	get_next_line(0, &line);
	player->map.height = ft_atoi(&line[8]);
	i = 8;
	while (line[i] != ' ')
		i++;
	player->map.width = ft_atoi(&line[i]);
	ft_strdel(&line);
	player->map.map = (char**)malloc(sizeof(char*) * player->map.height);
	i = 0;
	while (i < player->map.height)
		player->map.map[i++] = (char*)malloc(sizeof(char) *
												player->map.width + 1);
	player->copy_map = (char**)malloc(sizeof(char*) * player->map.height);
	i = 0;
	while (i < player->map.height)
		player->copy_map[i++] = (char*)malloc(sizeof(char) *
									player->map.width + 1);
}
