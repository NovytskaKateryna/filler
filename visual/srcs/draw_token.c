/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:43:26 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:54:39 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	fill_tok_block(t_vis *v, int x, int y, int color)
{
	int y1;
	int x1;
	int i;
	int j;

	y1 = v->tok_y + (y * v->tok_size) + v->tok_size + 1;
	x1 = v->tok_x + (x * v->tok_size) + v->tok_size + 1;
	j = v->tok_y + (y * v->tok_size) + 1;
	while (++j < y1)
	{
		i = v->tok_x + (x * v->tok_size) + 1;
		while (++i < x1)
			put_img_pixel(v, i, j, color);
	}
}

void	put_tok_figure(t_vis *v, int x, int y)
{
	while (++y < v->turn[v->turn_num].token_height)
	{
		x = -1;
		while (++x < v->turn[v->turn_num].token_width)
			if (v->turn[v->turn_num].token[y][x] == '*')
				fill_tok_block(v, x, y, TOKEN);
	}
}

void	draw_piece(t_vis *v, int x, int y)
{
	v->tok_size = v->block_size;
	v->tok_y = v->map_y - (v->map_y / 3) -
		(v->turn[v->turn_num].token_height * v->block_size);
	v->tok_x = v->map_x + (v->map_width * v->block_size) -
						(v->turn[v->turn_num].token_width * v->tok_size);
	y = v->tok_y + v->turn[v->turn_num].token_height * v->tok_size + 1;
	x = v->tok_x + v->turn[v->turn_num].token_width * v->tok_size + 1;
	put_tok_figure(v, -1, -1);
}
