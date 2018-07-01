/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:25:13 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 20:25:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	determine_direction(t_player *player, int x, int y)
{
	if (player->my_pos[X] > x)
		player->direction = LEFT;
	if (player->my_pos[X] < x)
		player->direction = RIGHT;
	if (player->my_pos[Y] > y)
		player->direction = UP;
	if (player->my_pos[Y] < y)
		player->direction = DOWN;
	if (player->my_pos[X] > x && player->my_pos[Y] > y)
		player->direction = UP_LEFT;
	if (player->my_pos[X] > x && player->my_pos[Y] < y)
		player->direction = DOWN_LEFT;
	if (player->my_pos[X] < x && player->my_pos[Y] > y)
		player->direction = UP_RIGHT;
	if (player->my_pos[X] < x && player->my_pos[Y] < y)
		player->direction = DOWN_RIGHT;
}
