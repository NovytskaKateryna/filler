/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:54:56 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:55:08 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	fill_block(t_vis *v, int x, int y, int color)
{
	int y1;
	int x1;
	int i;
	int j;

	y1 = v->map_y + (y * v->block_size) + v->block_size;
	x1 = v->map_x + (x * v->block_size) + v->block_size;
	j = v->map_y + (y * v->block_size) + 1;
	while (++j < y1)
	{
		i = v->map_x + (x * v->block_size) + 1;
		while (++i < x1)
			put_img_pixel(v, i, j, color);
	}
}

void	put_figures(t_vis *v, int x, int y)
{
	y = -1;
	while (++y < v->map_height)
	{
		x = -1;
		while (++x < v->map_width)
		{
			if (v->turn[v->turn_num].map[y][x] == 'X')
				fill_block(v, x, y, P2_COLOR);
			if (v->turn[v->turn_num].map[y][x] == 'x')
				fill_block(v, x, y, P2_LAST);
			if (v->turn[v->turn_num].map[y][x] == 'O')
				fill_block(v, x, y, P1_COLOR);
			if (v->turn[v->turn_num].map[y][x] == 'o')
				fill_block(v, x, y, P1_LAST);
		}
	}
}
