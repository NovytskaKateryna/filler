/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:40:13 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:41:33 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	players_color(t_vis *v, int scale)
{
	int x;
	int y;

	y = v->map_y - scale + 3;
	while (++y < (v->map_y - scale + 23))
	{
		x = v->map_x + 100;
		while (++x < (v->map_x + 100 + (int)(ft_strlen(v->p1_name) * 10)))
			put_img_pixel(v, x, y, P1_COLOR);
	}
	y = v->map_y - scale + 53;
	while (++y < (v->map_y - scale + 73))
	{
		x = v->map_x + 100;
		while (++x < (v->map_x + 100 + (int)(ft_strlen(v->p2_name) * 10)))
			put_img_pixel(v, x, y, P2_COLOR);
	}
}

void	put_winner(t_vis *v)
{
	int x;
	int y;

	x = v->map_x + (v->map_width * v->block_size) / 2;
	y = v->map_y + v->map_height * v->block_size + 80;
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x - 40,
			y - 50, 0xffffff, "* WINNER *");
	if (v->p1_score == v->p2_score)
	{
		mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x - 15,
				y, 0xffffff, "Both players");
		return ;
	}
	if (v->p1_score > v->p2_score)
	{
		x -= ((ft_strlen(v->p1_name) * 5) - 5);
		mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x, y, 0xffffff, v->p1_name);
	}
	else
	{
		x -= ((ft_strlen(v->p2_name) * 5) - 5);
		mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x, y, 0xffffff, v->p2_name);
	}
}

void	put_score(t_vis *v)
{
	int		x;
	int		y;
	char	*score1;
	char	*score2;

	score1 = ft_itoa(v->p1_score);
	score2 = ft_itoa(v->p2_score);
	x = v->map_x;
	y = v->map_y + v->map_height * v->block_size + 10;
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x, y, 0xffffff, "Player1:");
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x + 85,
			y, 0xffffff, score1);
	x = v->map_x + v->map_width * v->block_size - 100 - ft_strlen(score2) * 8;
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x, y, 0xffffff, "Player2:");
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, x + 85,
			y, 0xffffff, score2);
	ft_strdel(&score1);
	ft_strdel(&score2);
}

void	put_players(t_vis *v, int scale)
{
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, v->map_x,
					v->map_y - scale, 0xffffff, "Player1");
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, v->map_x + 100,
					v->map_y - scale, 0xffffff, v->p1_name);
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, v->map_x,
					v->map_y - scale + 50, 0xffffff, "Player2");
	mlx_string_put(v->p.mlx_ptr, v->p.win_ptr, v->map_x + 100,
					v->map_y - scale + 50, 0x202019, v->p2_name);
}
