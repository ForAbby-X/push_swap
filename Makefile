# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:39:09 by alde-fre          #+#    #+#              #
#    Updated: 2023/04/11 22:16:15 by alde-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

# directories
SRCDIR	=	./src
INCDIR	=	-I ./inc
OBJDIR	=	./obj

# src / includes / obj files
SRC		=	push_swap/main.c \
			push_swap/context.c \
			push_swap/parsing.c \
			push_swap/utils.c \
			push_swap/solver/solver.c \
			push_swap/solver/utils.c \
			push_swap/solver/mover.c \
			push_swap/solver/small_solve.c\
			 \
			pile/init.c \
			pile/add.c \
			pile/remove.c \
			pile/copy.c \
			pile/display.c \
			pile/conditions.c \
			pile/rotation.c \
			pile/geter.c \
			 \
			actions/push.c \
			actions/reverse_rotate.c \
			actions/rotate.c \
			actions/swap.c \
			 \
			checker/main.c \
			checker/ordered.c \
			checker/do_action.c

INC		= 

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= cc
CFLAGS	= -MMD -MP -Wall -Wextra -Werror -pg

all: obj $(NAME)

raw: CFLAGS += -O0
raw: all

fast: CFLAGS += -Ofast
fast: all

debug: CFLAGS += -g3
debug: all

obj:
	@rm -rf .print
	@mkdir -p $(OBJDIR)

.print:
	@> $@
	@echo "\e[1;36mCompiling...\e[0m"

$(NAME): $(OBJ)
	@echo "\e[1;35mLinking...\e[0m"
	@$(CC) -pg -o $(NAME) $+
	@echo "\e[1;32m➤" $@ "created succesfully !\e[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c .print
	@echo "\e[0;36m ↳\e[0;36m" $<"\e[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

temp:
	@echo "\e[1;36mCompiling...\e[0m";

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
