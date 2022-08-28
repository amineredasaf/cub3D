# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:42:39 by rsaf              #+#    #+#              #
#    Updated: 2022/08/28 15:03:29 by yabtaour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

C_FLAGS		=	-Wall -Wextra -Werror

PARSING		=	parsing.c

EXECUTION	=

INCLUDES	=	./includes/cub3d.h ./includes/parsing.h ./includes/structrs.h ./includes/execution.h

ALL_FILES	=	main.c $(PARSING) $(EXECUTION)

OBJ			=	$(ALL_FILES:.c=.o)

all			:	$(NAME)

%.o			:	%.c	$(INCLUDES)
	cc	$(C_FLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
	cc $(C_FLAGS) $^ -o $@

clean		:
	rm -f $(OBJ)

fclean		: clean
	rm -f $(NAME)

re			: fclean all