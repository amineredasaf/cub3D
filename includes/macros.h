/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/02 14:07:57 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

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
# define W_FIRST_LAST 1
# define W_INSIDE 2
# define W_LAST 3


/*				dubg				*/

# define HERE printf("was here\n");
#endif // MACROS_H
