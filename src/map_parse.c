/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:22:08 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 19:37:03 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	up_left(t_player *player)
{
	int	y;
	int	x;

	y = player->op_pos[Y] - player->token.height;
	while (++y < player->map.height + player->token.height)
	{
		x = player->op_pos[X] - player->token.width;
		while (++x < player->map.width + player->token.width)
		{
			check_piece(player, x, y);
			if (player->placed)
				distance_to_me(player, x, y);
			player->placed = 0;
		}
	}
	player->up_left = 1;
	if (player->result[X] == 0 && player->result[Y] == 0 &&
		!(player->down_right))
		down_right(player);
}

void	up_right(t_player *player)
{
	int	y;
	int	x;

	y = player->op_pos[Y] - player->token.height;
	while (++y < player->map.height + player->token.height)
	{
		x = player->op_pos[X] + player->token.width;
		while (--x >= -player->token.width)
		{
			check_piece(player, x, y);
			if (player->placed)
				distance_to_me(player, x, y);
			player->placed = 0;
		}
	}
	player->up_right = 1;
	if (player->result[X] == 0 && player->result[Y] == 0 &&
		!(player->down_left))
		down_left(player);
}

void	down_left(t_player *player)
{
	int	y;
	int	x;

	y = player->op_pos[Y] + player->token.height;
	while (--y >= -player->token.height)
	{
		x = player->op_pos[X] - player->token.width;
		while (++x < player->map.width + player->token.width)
		{
			check_piece(player, x, y);
			if (player->placed)
				distance_to_me(player, x, y);
			player->placed = 0;
		}
	}
	player->down_left = 1;
	if (player->result[X] == 0 && player->result[Y] == 0 &&
		!(player->up_right))
		up_right(player);
}

void	down_right(t_player *player)
{
	int	y;
	int	x;

	y = player->op_pos[Y] + player->token.height;
	while (--y >= -player->token.height)
	{
		x = player->op_pos[X] + player->token.width;
		while (--x >= -player->token.width)
		{
			check_piece(player, x, y);
			if (player->placed)
				distance_to_me(player, x, y);
			player->placed = 0;
		}
	}
	player->down_right = 1;
	if (player->result[X] == 0 && player->result[Y] == 0 &&
		!(player->up_left))
		up_left(player);
}
