/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:05 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/27 13:17:45 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	compare_map(t_player *player)
{
	int x;
	int y;
	int check_last;

	y = -1;
	check_last = 1;
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
		{
			if (player->map.map[y][x] == player->op_num &&
									!(player->op_touched))
				check_touched(player, x, y);
			if (player->map.map[y][x] == player->op_num &&
				player->map.map[y][x] != player->copy_map[y][x])
				check_last = 0;
		}
	}
	if (check_last == 1)
		player->op_blocked = 1;
}

void	write_strategy(char score, t_player *player, int y, int x)
{
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
		{
			if (player->map.map[y][x] == player->op_num ||
				(player->map.map[y][x] >= '0' && player->map.map[y][x] <= '9'))
			{
				if (x - 1 >= 0)
					if (player->map.map[y][x - 1] == '.')
						player->map.map[y][x - 1] = score;
				if (y - 1 >= 0)
					if (player->map.map[y - 1][x] == '.')
						player->map.map[y - 1][x] = score;
				if (y + 1 < player->map.height)
					if (player->map.map[y + 1][x] == '.')
						player->map.map[y + 1][x] = score;
				if (x + 1 < player->map.width)
					if (player->map.map[y][x + 1] == '.')
						player->map.map[y][x + 1] = score;
			}
		}
	}
}

void	get_map_data(t_player *player)
{
	char score;

	score = '9';
	write_map(player, 0);
	write_piece(player, 0);
	if (player->compare)
		compare_map(player);
	if (player->compare == 0)
		player->compare = 1;
	copy_map(player);
	while (score > '0')
	{
		write_strategy(score, player, -1, 0);
		score--;
	}
	fill_map(player);
}
