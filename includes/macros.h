/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 12:35:58 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*              win size            */

# define W_X 1000
# define W_Y 1000

/*              movement            */

# define R_S 0.174533
# define M_S 15

/*              execution           */
# define ADD 1
# define SUB 0

# define BLOCK_W 64
# define BLOCK_H 64
# define PI 3.14159265359
# define H_FOV 0.5236
# define ANGLE_STEP 0.001047198
# define P_PP_D 954.929249292

# define LEFT -1
# define RIGHT 1

/*              img size            */

# define IMG_S 10

/*              vectors             */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define TRUE 1
# define FALSE 0

/*				sides				*/
# define S_NO 10
# define S_SO 11
# define S_WE 12
# define S_EA 13
# define S_F  14
# define S_C  15

/*              texture sides       */
# define NO 0
# define SO 1
# define WE 2
# define EA 3

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

#endif // MACROS_H
