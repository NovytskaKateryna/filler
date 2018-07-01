/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:23:50 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 20:24:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	distance_to_op(t_player *player, int x, int y)
{
	int	distance;

	distance = ABS(player->my_pos[X] - x) +
				ABS(player->my_pos[Y] - y);
	if (distance < player->distance_to_enemy)
	{
		player->op_close[X] = x;
		player->op_close[Y] = y;
		player->distance_to_enemy = distance;
	}
}

void	distance_to_me(t_player *player, int x, int y)
{
	int	distance;

	distance = ABS(player->op_pos[X] - player->my_pos[X]) +
			ABS(player->op_pos[Y] - player->my_pos[Y]);
	if (distance < player->distance_to_me)
	{
		player->result[X] = x;
		player->result[Y] = y;
		player->distance_to_me = distance;
	}
}
