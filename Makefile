# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:39:09 by alde-fre          #+#    #+#              #
#    Updated: 2023/04/13 02:30:43 by mcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_BONUS = checker

# directories
SRCDIR	=	./src
INCDIR	=	-I ./inc
OBJDIR	=	./obj

# src / includes / obj files
SRC		=	push_swap/context.c \
			push_swap/parsing.c \
			push_swap/utils.c \
			 \
			pile/init.c \
			pile/add.c \
			pile/remove.c \
			pile/copy.c \
			pile/conditions.c \
			pile/rotation.c \
			pile/geter.c \
			 \
			actions/push.c \
			actions/reverse_rotate.c \
			actions/rotate.c \
			actions/swap.c \
			\
			checker/ordered.c

SRC_MAIN	= push_swap/main.c \
			push_swap/solver/solver.c \
			push_swap/solver/utils.c \
			push_swap/solver/mover.c \
			push_swap/solver/small_solve.c

SRC_BONUS =	checker/main.c \
			checker/do_action.c \
			checker/get_next_line.c \
			checker/get_next_line_utils.c \
			checker/execute_actions.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o)) $(addprefix $(OBJDIR)/,$(SRC_MAIN:.c=.o))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o)) $(addprefix $(OBJDIR)/,$(SRC_BONUS:.c=.o))

# compiler
CC		= cc
CFLAGS	= -MMD -MP -Wall -Wextra -Werror

all: obj $(NAME)

bonus: obj $(NAME_BONUS)

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
	@$(CC) -pg -o $@ $+
	@echo "\e[1;32m➤" $@ "created succesfully !\e[0m"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "\e[1;35mLinking...\e[0m"
	@$(CC) -pg -o $@ $+
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
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
