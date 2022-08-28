/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:22:20 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/28 21:24:40 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
#define UTILS_H

#include "structs.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../Get_next_line/get_next_line.h"

char	*ft_substr(char *s, int start, size_t len);

#endif // UTILS_H