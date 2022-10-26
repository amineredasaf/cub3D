# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:42:39 by rsaf              #+#    #+#              #
#    Updated: 2022/10/26 16:33:27 by rsaf             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CFLAGS		:=	-Wall -Wextra -Werror -g

MLX			=	-lmlx -framework OpenGL -framework AppKit

PARSING		=	./parsing/parsing.c ./parsing/parse_textures.c \
				./parsing/parse_map.c ./parsing/parsing_utils.c \
            	./parsing/get_colors.c ./parsing/ft_isvalid.c \
				./parsing/ft_fill_lines.c ./parsing/ft_read_file.c \


UTILS		=	./utils/ft_substr.c ./utils/ft_strcmp.c \
				./utils/ft_print_error.c ./utils/ft_strdup.c \
				./utils/ft_strtrim.c ./utils/ft_isspace.c \
				./utils/ft_split.c ./utils/ft_calloc.c \
				./utils/ft_atoi.c \
				
INIT		=	./initialization/initialize_data.c \
				./initialization/mlx_initialization.c \

EXECUTION	=	./execution/execution.c ./execution/execution_utils.c \
				./execution/hor.c ./execution/ver.c ./execution/ft_mlx.c\
				./execution/moves.c \

GNL			=	./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c

INCLUDES	=	./includes/cub3d.h ./includes/parsing.h ./includes/structrs.h \
				./includes/execution.h ./Get_next_line/get_next_line.h \
				./includes/utils.h ./includes/macros.h \

ALL_FILES	=	main.c $(PARSING) $(EXECUTION) $(GNL) $(UTILS) $(INIT)

OBJ			=	$(ALL_FILES:.c=.o)

all			:	$(NAME)

%.o			:	%.c	$(INCLUDES)
	cc	$(CFLAGS) -g -c $< -o $@

test		:
	cc $(MLX) mlx_testing.c

$(NAME)		: $(OBJ)
	cc $(C_FLAGS) $^ $(MLX) -o $@ -fsanitize=address

clean		:
	rm -f $(OBJ)

hh			:
	make && make clean && clear

fclean		: clean
	rm -f $(NAME)
re			: fclean all