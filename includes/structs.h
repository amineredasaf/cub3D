/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:40:12 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/29 04:15:00 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_textures
{
	int		n_no;
	int 	n_so;
	int 	n_we;
	int 	n_ea;
	char	*no_txt;
	char	*so_txt;
	char	*we_txt;
	char	*ea_txt;
}	t_textures;


typedef struct s_data
{
	char		**av;
	int			ac;
	int			fd_map[2]; // file-descriptor of the map
	char		**file_content; // file content *line by line*
	t_textures	sides;
}   t_data;

#endif // STRUCTS_H
