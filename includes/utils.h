/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:22:20 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/31 11:53:02 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
#define UTILS_H

#include "structs.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../Get_next_line/get_next_line.h"

/*			strings utils		*/
char	*ft_substr(char *s, int start, size_t len);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strtrim(char *s1, char *set);
int     ft_isspace(char c);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t	count, size_t	size);

/*          Error utils         */
int		ft_print_error(char *str);

/*          initialization      */
void	ft_initialize_data(t_data *data);

#endif // UTILS_H