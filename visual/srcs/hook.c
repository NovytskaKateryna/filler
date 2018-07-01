/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:55:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:55:37 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	delete_token(t_vis *v, int num)
{
	int	n;

	n = -1;
	if (v->turn[num].token != NULL)
	{
		while (++n < v->turn[num].token_height)
			ft_strdel(&v->turn[num].token[n]);
		free(v->turn[num].token);
	}
}

void	delete_map(t_vis *v, int num)
{
	int	n;

	n = -1;
	if (v->turn->map != NULL)
	{
		while (++n < v->map_height)
			ft_strdel(&v->turn[num].map[n]);
		free(v->turn[num].map);
	}
}

int		program_exit(t_vis *v)
{
	int num;

	num = -1;
	while (++num < v->max_turns)
	{
		delete_token(v, num);
		delete_map(v, num);
	}
	free(v->turn);
	exit(0);
}

int		key_hook(int keycode, t_vis *v)
{
	if (keycode == 53)
		program_exit(v);
	if (keycode == 124 && (v->turn_num + 1) < v->max_turns)
		v->turn_num += 1;
	if (keycode == 123 && (v->turn_num - 1) >= 0)
		v->turn_num -= 1;
	redraw(v);
	return (0);
}
