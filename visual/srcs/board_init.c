/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:41:46 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:42:21 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	board_init(t_vis *v)
{
	v->turn_num = 0;
	v->p.mlx_ptr = mlx_init();
	v->p.win_ptr = mlx_new_window(v->p.mlx_ptr, WIDTH, HEIGHT, "FILLER");
	v->p.img_ptr = mlx_new_image(v->p.mlx_ptr, WIDTH, HEIGHT);
	v->p.image = mlx_get_data_addr(v->p.img_ptr, &v->p.bpp,
			&v->p.size_line, &v->p.endian);
	v->b_image = (int*)mlx_get_data_addr(v->background,
			&v->p.bpp, &v->p.size_line, &v->p.endian);
	v->p.bpp /= 8;
	redraw(v);
	mlx_hook(v->p.win_ptr, 2, 0, key_hook, v);
	mlx_hook(v->p.win_ptr, 17, 1L << 17, program_exit, v);
	mlx_loop(v->p.mlx_ptr);
}
