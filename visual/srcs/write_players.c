/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:28:59 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:30:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	write_p1(t_vis *v, char *line)
{
	int i;
	int n;
	int j;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '.')
		{
			n = i - 1;
			j = 0;
			while ((line[n] >= 'a' && line[n] <= 'z') ||
				(line[n] >= '0' && line[n] <= '9'))
				n--;
			n++;
			while ((line[n] >= 'a' && line[n] <= 'z') ||
				(line[n] >= '0' && line[n] <= '9'))
				v->p1_name[j++] = line[n++];
			v->p1_name[j] = '\0';
		}
	}
}

void	write_p2(t_vis *v, char *line)
{
	int i;
	int n;
	int j;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '.')
		{
			n = i - 1;
			j = 0;
			while ((line[n] >= 'a' && line[n] <= 'z') ||
				(line[n] >= '0' && line[n] <= '9'))
				n--;
			n++;
			while ((line[n] >= 'a' && line[n] <= 'z') ||
				(line[n] >= '0' && line[n] <= '9'))
				v->p2_name[j++] = line[n++];
			v->p2_name[j] = '\0';
		}
	}
}

void	get_players_names(t_vis *v)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 6)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	get_next_line(0, &line);
	write_p1(v, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	write_p2(v, line);
	ft_strdel(&line);
}
