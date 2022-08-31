/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:40:12 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/31 11:27:22 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_textures
{
	int		f_found;
	int		n_no;
	int 	n_so;
	int 	n_we;
	int 	n_ea;
	int		n_f;
	int		n_c;
	char	*no_txt;
	char	*so_txt;
	char	*we_txt;
	char	*ea_txt;
	char	*f_txt;
	char	*c_txt;
}	t_textures;

typedef struct s_color
{
	char	**splited;
	int		r;
	int		b;
	int		g;
}	t_color;


typedef struct s_data
{
	char		**av;
	int			ac;
	int			fd_map[2]; // file-descriptor of the map
	char		**file_content; // file content *line by line*
	t_color		floor;
	t_color		ceiling;
	t_textures	sides;
}   t_data;

#endif // STRUCTS_H
