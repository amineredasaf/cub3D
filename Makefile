# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:42:39 by rsaf              #+#    #+#              #
#    Updated: 2022/08/28 22:37:29 by rsaf             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

C_FLAGS		=	-Wall -Wextra -Werror

PARSING		=	./parsing/parsing.c

UTILS		=	./utils/ft_substr.c ./utils/ft_strcmp.c ./utils/ft_print_error.c \
				

EXECUTION	=

GNL			=	./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c

INCLUDES	=	./includes/cub3d.h ./includes/parsing.h ./includes/structrs.h \
				./includes/execution.h ./Get_next_line/get_next_line.h \
				./includes/utils.h ./includes/macros.h \

ALL_FILES	=	main.c $(PARSING) $(EXECUTION) $(GNL) $(UTILS)

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