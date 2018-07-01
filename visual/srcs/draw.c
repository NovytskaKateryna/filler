/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:42:38 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:43:10 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	horizontal(t_vis *v, int x1, int y1)
{
	int size;
	int y;
	int x;

	size = -1;
	y = v->map_y;
	while (++y <= y1)
	{
		x = v->map_x;
		if (size == v->block_size || size == -1 || y == y1)
		{
			while (++x <= x1)
			{
				put_img_pixel(v, x, y, 0x241c3b);
				if (size == -1 || y == y1)
					put_img_pixel(v, x, y, 0xeff8f9);
			}
			size = 0;
		}
		if (size != -1)
			size++;
	}
}

void	vertical(t_vis *v, int x1, int y1)
{
	int size;
	int y;
	int x;

	size = -1;
	x = v->map_x;
	while (++x <= x1)
	{
		y = v->map_y;
		if (size == v->block_size || size == -1 || x == x1)
		{
			while (++y <= y1)
			{
				put_img_pixel(v, x, y, 0x241c3b);
				if (size == -1 || x == x1)
					put_img_pixel(v, x, y, 0xeff8f9);
			}
			size = 0;
		}
		if (size != -1)
			size++;
	}
}

void	draw(t_vis *v)
{
	int scale;
	int x1;
	int y1;

	scale = (v->map_height * v->block_size) / 4;
	v->map_x = WIDTH / 2 - ((v->map_width * v->block_size) / 2);
	v->map_y = HEIGHT / 2 - ((v->map_height * v->block_size) / 2);
	y1 = v->map_y + (v->map_height * v->block_size);
	x1 = v->map_x + (v->map_width * v->block_size);
	horizontal(v, x1, y1);
	vertical(v, x1, y1);
	put_figures(v, 0, 0);
	draw_piece(v, 0, 0);
	players_color(v, scale);
	mlx_put_image_to_window(v->p.mlx_ptr, v->p.win_ptr, v->p.img_ptr, 0, 0);
	put_players(v, scale);
	if (v->turn_num == v->max_turns - 1)
	{
		put_score(v);
		put_winner(v);
	}
}
