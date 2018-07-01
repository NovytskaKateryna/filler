# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:34:33 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/24 14:34:35 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer.knovytsk

SRCS_PATH = srcs
OBJS_PATH = objs

SRCS = main.c draw.c image.c board_init.c hook.c figures.c \
		add_draw.c write_data.c write_players.c draw_token.c
OBJS = $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
INCLUDES = -I includes

CC = gcc -Wall -Wextra -Werror
FLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast -O3

all: $(NAME)

$(OBJS): | $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
	@$(CC) -c $< $(INCLUDES) -o $@

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) ../libft/libft.a $(FLAGS)
	@echo "\033[35;1mVisualization\033[0m"

clean:
	@rm -f $(OBJS)
	@rm -rf bin objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all