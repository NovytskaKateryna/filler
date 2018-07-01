/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:32:58 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:40:00 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	write_score(t_vis *v, char *line)
{
	int		count;

	count = 1;
	while (count != 0)
	{
		get_next_line(0, &line);
		if (line[0] == 'P' && line[1] == 'l')
			count = 0;
		else if (line[0] == '=')
		{
			v->p1_score = ft_atoi(&line[10]);
			ft_strdel(&line);
			get_next_line(0, &line);
			v->p2_score = ft_atoi(&line[10]);
			count = 0;
		}
		ft_strdel(&line);
	}
}

void	write_turns(t_vis *v)
{
	char	*line;
	int		turn;

	turn = 0;
	while (get_next_line(0, &line))
	{
		ft_strdel(&line);
		write_map(v, &v->turn[turn], 0, -1);
		write_piece(&v->turn[turn], 0, -1);
		write_score(v, line);
		turn++;
	}
	v->max_turns = turn;
}

int		main(void)
{
	t_vis	v;
	char	*line;
	int		i;

	get_players_names(&v);
	get_next_line(0, &line);
	v.map_height = ft_atoi(&line[8]);
	i = 8;
	while (line[i] != ' ')
		i++;
	v.map_width = ft_atoi(&line[i]);
	ft_strdel(&line);
	v.turn = (t_turn*)malloc(sizeof(t_turn) * NUM_TURNS);
	i = -1;
	while (++i < NUM_TURNS)
	{
		v.turn[i].token = NULL;
		v.turn[i].map = NULL;
	}
	write_turns(&v);
	v.block_size = ((WIDTH / v.map_width) + (HEIGHT / v.map_height)) / 3.5;
	board_init(&v);
	return (0);
}
