/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:22:24 by knovytsk          #+#    #+#             */
/*   Updated: 2018/04/30 20:23:25 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_player	player;
	char		*line;

	line = NULL;
	reset(&player);
	get_info(&player, line);
	player.compare = 0;
	player.op_touched = 0;
	player.op_blocked = 0;
	while (get_next_line(0, &line))
	{
		ft_strdel(&line);
		get_map_data(&player);
		analyze(&player);
		reset(&player);
		delete_token(&player);
	}
	delete_map(&player, player.map.map);
	delete_map(&player, player.copy_map);
	return (0);
}
