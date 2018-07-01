/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:15:28 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/27 13:17:14 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_to_closest(t_player *player)
{
	if (player->direction == UP_LEFT || player->direction == UP ||
		player->direction == LEFT)
		up_left(player);
	else if (player->direction == UP_RIGHT || player->direction == RIGHT)
		up_right(player);
	else if (player->direction == DOWN_LEFT || player->direction == DOWN)
		down_left(player);
	else if (player->direction == DOWN_RIGHT)
		down_right(player);
}

void	check_score_placed(t_player *player, int x, int y)
{
	int score;

	score = 0;
	player->placed = 0;
	score = check_piece(player, x - player->token.width,
								y - player->token.height);
	if (player->placed)
	{
		if (score > player->score)
		{
			player->score = score;
			player->result[X] = x - player->token.width;
			player->result[Y] = y - player->token.height;
		}
	}
	player->placed = 0;
}

void	check_distance_to_op(t_player *player, int my_x, int my_y)
{
	int x;
	int y;

	y = -1;
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
		{
			if (player->op_touched && !player->op_blocked)
				check_score_placed(player, x, y);
			else if (player->map.map[y][x] == player->op_num &&
					(!(player->op_touched) || player->op_blocked))
			{
				player->my_pos[X] = my_x;
				player->my_pos[Y] = my_y;
				distance_to_op(player, x, y);
			}
		}
	}
}

void	check_distance(t_player *player, int last_x, int last_y)
{
	int	y;
	int	x;

	y = -1;
	last_x = 1;
	last_y = 1;
	while (++y < player->map.height)
	{
		x = -1;
		while (++x < player->map.width)
		{
			if (player->map.map[y][x] == player->my_num)
				check_distance_to_op(player, x, y);
		}
	}
}

void	analyze(t_player *player)
{
	check_distance(player, 0, 0);
	if (!(player->op_touched) || player->op_blocked)
	{
		player->op_pos[X] = player->op_close[X];
		player->op_pos[Y] = player->op_close[Y];
		determine_direction(player, player->op_pos[X], player->op_pos[Y]);
		place_to_closest(player);
		if (!is_placed(player))
			place_in_other(player);
	}
	ft_printf("%d %d\n", player->result[Y], player->result[X]);
}
