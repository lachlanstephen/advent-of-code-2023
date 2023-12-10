# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstephen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 18:49:21 by lstephen          #+#    #+#              #
#    Updated: 2023/12/10 21:41:18 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipe-maze

SRC				= main.c			\
				  file_parsing.c	\
				  pipe_maze.c		\

SRCPRE			= $(addprefix $(SRCDIR), $(SRC))

SRCDIR			= ./src/

OBJS			= $(SRCPRE:.c=.o)

OUTPUT			= .output

HEADER			= ./includes/

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling Objects$(NC) ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ $(GREEN)Compiling Program$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing Programs$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(OUTPUT) $(OBJS)
	@$(PROGRAM_COMP)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OUTPUT):
	@$(BEGIN_COMP)
	@echo "" > .output

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean:
	@$(CLEAN_MSG)
	rm -f $(OBJS) $(OUTPUT)

fclean: clean
	@$(FCLEAN_MSG)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re OBJCOUNT
