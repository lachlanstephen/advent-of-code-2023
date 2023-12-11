# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:47:21 by lstephen          #+#    #+#              #
#    Updated: 2023/12/11 18:17:32 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cosmic-expansion

SRC				= main.c		\
				file_parsing.c	\

SRCPRE			= $(addprefix $(SRCDIR), $(SRC))

SRCDIR			= ./src/

OBJS			= $(SRCPRE:.c=.o)

OBJ_OUTPUT		= .output

HEADER			= ./includes/

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Wpedantic

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

$(NAME): $(OBJ_OUTPUT) $(OBJS)
	@$(PROGRAM_COMP)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_OUTPUT):
	@$(BEGIN_COMP)
	@touch $(OBJ_OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean:
	@$(CLEAN_MSG)
	rm -f $(OBJS) $(OBJ_OUTPUT)

fclean: clean
	@$(FCLEAN_MSG)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
