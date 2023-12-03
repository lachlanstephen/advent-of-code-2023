# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstephen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 17:02:27 by lstephen          #+#    #+#              #
#    Updated: 2023/12/03 03:08:46 by darkwater        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cube-conundrum

SRC				= main.c		\
				  parse_file.c	\
				  print_num.c	\

SRCPRE			= $(addprefix $(PREFIX), $(SRC))

OBJS			= $(SRCPRE:.c=.o)

PREFIX			= ./src/

HEADER			= ./includes/

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Wpedantic

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
