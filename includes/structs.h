/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:40:12 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/29 02:42:33 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_data
{
	char	**av;
	int		ac;
	int		fd_map[2]; // file-descriptor of the map
	char	**file_content; // file content *line by line*
}   t_data;

#endif // STRUCTS_H
