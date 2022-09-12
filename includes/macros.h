/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/07 13:20:16 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

/*              win size            */

# define W_X 1000
# define W_Y 1000

/*              execution           */
# define ADD 1
# define SUB 0

# define BLOCK_W 64
# define BLOCK_H 64
# define PI 3.14
# define FOV 60
# define ANGLE_STEP 0.1875

/*              img size            */

# define IMG_S 10

/*              vectors             */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define TRUE 1
# define FAlSE 0

/*				sides				*/
# define S_NO 10
# define S_SO 11
# define S_WE 12
# define S_EA 13
# define S_F  14
# define S_C  15

/*				characters			*/

# define C_WALL '1'
# define C_EMPTY '0'
# define C_NORTH 'N'
# define C_SOUTH 'S'
# define C_EAST 'E'
# define C_WEST 'W'

/* 				ft_isside flag		*/
# define SIDE 1
# define COLOR 0

/*				MAP					*/
# define W_FIRST 1
# define W_INSIDE 2
# define W_LAST 3


/*				Error				*/
# define E_WALLS "- Configuration Walls is not well formatted."
# define E_CHARACTERS "- Configuration Characters, Not Well Formatted."
# define E_FILE_FORMAT "- Configuration file is not well formatted."
# define E_ARGC_NB "- Invalid number of arguments : "
# define E_EMPTY_FILE "- Configuration file is empty."
# define E_ALLOCATION_FAILED "- Allocation error occurred."
# define E_PERMISSION_DENIED "- Can't access configuration file."
# define E_FILE_NAME "- Invalid name of the configuration file."
# define E_SUFFIX "- Invalid suffix of the configuration file."
# define E_TEXTURE "- Texture configuration is not correct"
# define E_COLOR "- Color Configuration is Not Correct."

/*				dubg				*/

# define HERE printf("was here\n");
#endif // MACROS_H
