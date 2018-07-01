/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:17:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 20:21:59 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_touch(t_player *player, int x, int y, int score)
{
	int	x1;
	int	y1;

	x1 = player->x1;
	y1 = player->y1;
	if (player->token.token[y1][x1] == '*')
	{
		if ((y + y1 < player->map.height) && (x + x1 < player->map.width) &&
			(y + y1 >= 0 && x + x1 >= 0))
		{
			if (player->map.map[y + y1][x + x1] == player->my_num)
			{
				player->touched++;
				player->my_pos[X] = x + player->x1;
				player->my_pos[Y] = y + player->y1;
			}
			else if (player->map.map[y + y1][x + x1] == player->op_num)
				player->touched += 2;
			if (player->map.map[y + y1][x + x1] >= '0' &&
				player->map.map[y + y1][x + x1] <= '9')
				score = player->map.map[y + y1][x + x1];
		}
	}
	return (score);
}

int	check_piece(t_player *player, int x, int y)
{
	int score;

	score = 0;
	player->touched = 0;
	player->y1 = -1;
	while (++player->y1 < player->token.height)
	{
		player->x1 = -1;
		while (++player->x1 < player->token.width)
		{
			score += check_touch(player, x, y, 0);
			if (player->token.token[player->y1][player->x1] == '*' &&
				(y + player->y1 >= player->map.height ||
				x + player->x1 >= player->map.width))
				player->touched += 2;
			if (player->token.token[player->y1][player->x1] == '*' &&
				(y + player->y1 < 0 || x + player->x1 < 0))
				player->touched += 2;
		}
	}
	if (player->touched == 1)
		player->placed = 1;
	return (score);
}
