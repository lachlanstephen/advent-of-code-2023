# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 15:56:05 by darkwater         #+#    #+#              #
#    Updated: 2023/12/09 13:02:57 by darkwater        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wasteland

SRC				= main.c			\
				  file_parsing.c	\
				  print_num.c		\
				  calcs.c			\

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
