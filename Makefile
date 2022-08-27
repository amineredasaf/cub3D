# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:42:39 by rsaf              #+#    #+#              #
#    Updated: 2022/08/27 03:37:21 by rsaf             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

C_FLAGS		=	-Wall -Wextra -Werror

PARSING		=	

EXECUTION	=

LIB			=	./LIB/cub3d.h ./LIB/parsing.h

ALL_FILES	=	main.c $(PARSING) $(EXECUTION)

OBJ			=	$(ALL_FILES:.c=.o)

all			:	$(NAME)

%.o			:	%.c	$(LIB)
	cc	$(C_FLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
	cc $(C_FLAGS) $^ -o $@

clean		:
	rm -f $(OBJ)

fclean		: clean
	rm -f $(NAME)

re			: fclean all