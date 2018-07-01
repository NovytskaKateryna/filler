/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:19:07 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/27 13:26:15 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define X 0
# define Y 1

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define UP_LEFT 5
# define UP_RIGHT 6
# define DOWN_LEFT 7
# define DOWN_RIGHT 8

typedef	struct	s_token
{
	char		**token;
	int			width;
	int			height;
}				t_token;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_player
{
	t_map		map;
	t_token		token;
	char		**copy_map;
	char		my_num;
	char		op_num;
	int			my_pos[2];
	int			op_pos[2];
	int			op_close[2];
	int			result[2];
	int			direction;
	int			compare;
	int			distance_to_enemy;
	int			distance_to_me;
	int			placed;
	int			touched;
	int			x1;
	int			y1;
	int			up_left;
	int			up_right;
	int			down_left;
	int			down_right;
	int			op_touched;
	int			score;
	int			op_blocked;
}				t_player;

void			get_map_data(t_player *player);
void			write_map(t_player *player, int i);
void			write_piece(t_player *player, int i);
void			get_info(t_player *player, char *line);
void			get_player_num(t_player *player, char num);
void			reset(t_player *player);
void			delete_map(t_player *player, char **map);
void			delete_token(t_player *player);
void			analyze(t_player *player);
void			fill_map(t_player *player);
void			copy_map(t_player *player);
void			place_in_other(t_player *player);
int				is_placed(t_player *player);
void			check_touched(t_player *player, int x, int y);
void			distance_to_me(t_player *player, int x, int y);
void			distance_to_op(t_player *player, int x, int y);
void			determine_direction(t_player *player, int x, int y);
void			up_left(t_player *player);
void			up_right(t_player *player);
void			down_left(t_player *player);
void			down_right(t_player *player);
int				check_piece(t_player *player, int x, int y);

#endif
