/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/26 17:32:55 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	clear_image(t_vis *v)
{
	ft_bzero(v->p.image, WIDTH * HEIGHT * v->p.bpp);
}

void	redraw(t_vis *v)
{
	clear_image(v);
	draw(v);
}

void	put_img_pixel(t_vis *v, unsigned int x, unsigned int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
		*(int*)(v->p.image + (x + y * WIDTH) * v->p.bpp) = color;
}
