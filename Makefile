# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:42:39 by rsaf              #+#    #+#              #
#    Updated: 2022/08/31 11:52:11 by yabtaour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

C_FLAGS		=	-Wall -Wextra -Werror

PARSING		=	./parsing/parsing.c ./parsing/parse_textures.c \
				./parsing/parsing_utils.c ./parsing/get_colors.c \

UTILS		=	./utils/ft_substr.c ./utils/ft_strcmp.c \
				./utils/ft_print_error.c ./utils/ft_strdup.c \
				./utils/ft_strtrim.c ./utils/ft_isspace.c \
				./utils/ft_split.c ./utils/ft_calloc.c \
				
INIT		=	./initialization/initialize_data.c \

EXECUTION	=

GNL			=	./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c

INCLUDES	=	./includes/cub3d.h ./includes/parsing.h ./includes/structrs.h \
				./includes/execution.h ./Get_next_line/get_next_line.h \
				./includes/utils.h ./includes/macros.h \

ALL_FILES	=	main.c $(PARSING) $(EXECUTION) $(GNL) $(UTILS) $(INIT)

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