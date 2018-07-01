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

NAME = knovytsk.filler

SRCS_PATH = src
OBJS_PATH = obj

SRCS = main.c get_map_data.c distance.c direction.c \
        analyze.c map_parse.c utils.c map_utils.c \
        check_piece.c write_data.c
OBJS = $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
INCLUDES = -I inc
LIBINC = -I libft
LIBFT = -C libft
VISUAL = -C visual

CC = gcc -Wall -Wextra -Werror -OFast -O3

all: $(NAME)

$(OBJS): | $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
	@$(CC) -c $< $(INCLUDES) $(LIBINC) -o $@

$(NAME): $(OBJS)
	@echo "\033[33;1mCompilation of libft...\033[0m"
	@make $(LIBFT)
	@make $(VISUAL)
	@$(CC) -o $(NAME) $(OBJS) libft/libft.a
	@echo "\033[36;1mFIGHT THEM ALL\033[0m"

clean:
	@make clean $(LIBFT)
	@make clean $(VISUAL)
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf bin obj

fclean: clean
	@rm -f libft/libft.a
	@rm -f visual/visualizer.knovytsk
	@rm -f $(NAME)
	@echo "\033[32;1mCleaned\033[0m"

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all