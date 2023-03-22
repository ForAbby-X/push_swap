# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:39:09 by alde-fre          #+#    #+#              #
#    Updated: 2023/03/18 15:02:46 by alde-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

# directories
SRCDIR	=	./src
INCDIR	=	-I ./inc
OBJDIR	=	./obj

# src / includes / obj files
SRC		=	main.c \
			context.c \
			parsing.c \
			utils.c \
			 \
			pile/init.c \
			pile/add.c \
			pile/remove.c \
			 \
			actions/push.c \
			actions/reverse_rotate.c \
			actions/rotate.c \
			actions/swap.c \
			 \
			solver/solver.c \
			solver/utils.c

INC		= 

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= clang
CFLAGS	= -MMD -MP -Wall -Wextra -Werror

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
	@$(CC) -o $(NAME) $+
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
