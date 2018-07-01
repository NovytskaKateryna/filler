/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:56:17 by knovytsk          #+#    #+#             */
/*   Updated: 2018/05/02 14:58:50 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

# include <stdio.h>

# define WIDTH 	1000
# define HEIGHT 800

# define NUM_TURNS 100000

# define P1_COLOR 0xa94d5b
# define P1_LAST 0xf7d1d2
# define P2_COLOR 0x5da571
# define P2_LAST 0xe9f6b8
# define TOKEN 0xeedf76

typedef struct		s_ptr
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				bpp;
	int				size_line;
	int				endian;
}					t_ptr;

typedef struct		s_turn
{
	char			**token;
	char			**map;
	int				token_height;
	int				token_width;
}					t_turn;

typedef struct		s_vis
{
	t_ptr			p;
	t_turn			*turn;
	char			*winner;
	int				p1_score;
	int				p2_score;
	int				turn_num;
	int				max_turns;
	int				map_width;
	int				map_height;
	int				tok_x;
	int				tok_y;
	int				tok_size;
	int				map_x;
	int				map_y;
	int				block_size;
	void			*background;
	int				*b_image;
	int				b_height;
	int				b_width;
	char			p1_name[50];
	char			p2_name[50];
}					t_vis;

void				board_init(t_vis *v);
void				redraw(t_vis *v);
void				put_img_pixel(t_vis *v, unsigned int x,
								unsigned int y, int color);
void				draw(t_vis *v);
int					program_exit(t_vis *v);
int					key_hook(int keycode, t_vis *v);
void				fill_block(t_vis *v, int x, int y, int color);
void				put_figures(t_vis *v, int x, int y);
void				draw_piece(t_vis *v, int x, int y);
void				write_map(t_vis *v, t_turn *turn, int x, int y);
void				write_piece(t_turn *turn, int x, int y);
void				put_players(t_vis *v, int scale);
void				put_background(t_vis *v);
void				players_color(t_vis *v, int scale);
void				get_players_names(t_vis *v);
void				put_score(t_vis *v);
void				put_winner(t_vis *v);

#endif
