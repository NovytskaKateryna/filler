/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:14:15 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/27 13:18:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_placed(t_player *player)
{
	if (player->result[X] == 0 && player->result[Y] == 0)
		return (0);
	return (1);
}

void	place_in_other(t_player *player)
{
	if (!(player->up_left))
		up_left(player);
	if (!(player->up_right) && !(is_placed(player)))
		up_right(player);
	if (!(player->down_left) && !(is_placed(player)))
		down_left(player);
	if (!(player->down_right) && !(is_placed(player)))
		down_right(player);
}

void	fill_map(t_player *player)
{
	int y;
	int x;

	y = -1;
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
		{
			if (player->map.map[y][x] == '.')
				player->map.map[y][x] = '0';
		}
	}
}

void	copy_map(t_player *player)
{
	int x;
	int y;

	y = -1;
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
			player->copy_map[y][x] = player->map.map[y][x];
	}
}

void	check_touched(t_player *player, int x, int y)
{
	if (x - 2 >= 0 && x + 2 < player->map.width)
		if (player->map.map[y][x - 2] == player->my_num ||
			player->map.map[y][x + 2] == player->my_num)
			player->op_touched = 1;
	if (x - 1 >= 0 && x + 1 < player->map.width)
		if (player->map.map[y][x - 1] == player->my_num ||
			player->map.map[y][x + 1] == player->my_num)
			player->op_touched = 1;
}
