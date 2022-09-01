/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:01:10 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/01 09:01:04 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// THIS function incremente sides depends on the flag and return the path
char	*ft_textures_alloc(t_data *data, char *line, int flag)
{
	if (flag == S_NO)
		data->sides.n_no++;
	else if (flag == S_SO)
		data->sides.n_so++;
	else if (flag == S_WE)
		data->sides.n_we++;
	else if (flag == S_EA)
		data->sides.n_ea++;
	if (data->sides.n_no > 1 || data->sides.n_we > 1
		|| data->sides.n_so > 1 || data->sides.n_ea > 1)
		return (NULL);
	data->sides.f_found++;
	return (ft_strtrim(ft_strdup(&line[2]), " "));
}

// this function incremente colors depends on the flag and return the colors
char	*ft_color_alloc(t_data *data, char *line, int flag)
{
	if (flag == S_F)
		data->sides.n_f++;
	else if (flag == S_C)
		data->sides.n_c++;
	if (data->sides.n_f > 1 || data->sides.n_c > 1)
		return (NULL);
	data->sides.f_found++;
	return (ft_strtrim(ft_strdup(&line[1]), " "));
}

// this func alloact texture data in our struct. beta version could be better
int	ft_init_sides(t_data *data, char *line, int flag)
{
	int	len;

	if  (flag == S_NO)
		data->sides.no_txt = ft_textures_alloc(data, line, flag);
	else if (flag == S_SO)
		data->sides.so_txt = ft_textures_alloc(data, line, flag);
	else if  (flag == S_WE)
		data->sides.we_txt = ft_textures_alloc(data, line, flag);
	else if (flag == S_EA)
		data->sides.ea_txt = ft_textures_alloc(data, line, flag);
	else if (flag == S_F)
		data->sides.f_txt = ft_color_alloc(data, line, flag);
	else if (flag == S_C)
		data->sides.c_txt = ft_color_alloc(data, line, flag);
	if (data->sides.n_ea > 1 || data->sides.n_so > 1 || data->sides.n_we > 1
		|| data->sides.n_no > 1 || data->sides.n_f > 1 || data->sides.n_c > 1)
		{
			ft_print_error("- Configuration file is not Correct.");
			exit (1);
		}
	return (EXIT_SUCCESS);
}

// this func looks for sides and init them
int	ft_check_sides(t_data *data, char *line)
{
	if (ft_issides(line, 'N', 'O', SIDE))
		ft_init_sides(data, line, S_NO);
	else if (ft_issides(line, 'S', 'O', SIDE))
		ft_init_sides(data, line, S_SO);
	else if (ft_issides(line, 'W', 'E', SIDE))
		ft_init_sides(data, line, S_WE);
	else if (ft_issides(line, 'E', 'A', SIDE))
		ft_init_sides(data, line, S_EA);
	else if (ft_issides(line, 'F', 'q', COLOR))
		ft_init_sides(data, line, S_F);
	else if (ft_issides(line, 'C', 'q', COLOR))
		ft_init_sides(data, line, S_C);
	else if (line[0] != '1' && line[0] != '0' && line[0] != '\n')
		exit(ft_print_error("- Configuration file is not Correct."));
	return (EXIT_SUCCESS);
}

// this func looks for texture from the conf file and parse them
int	ft_parse_textures(t_data *data)
{
	char *line;
	int	x;

	x = 0;
	while (data->file_content[x])
	{
		line = ft_strtrim(data->file_content[x], " ");
		if (line && !ft_is_map(line))
			ft_check_sides(data, line);
		else if (data->sides.f_found < 6)
			exit(ft_print_error("- Configuration file is not Correct."));
		else if (ft_is_map(line))
			break;
		free(line);
		x++;
	}
	if (x != 0)
		data->map_s.start_point = x;
	if (ft_check_after_id(data))
		exit(ft_print_error("- Texture configuration is not correct"));
	ft_update_txt(data);
	printf("no	: |%s|\n", data->sides.no_txt);
	printf("so	: |%s|\n", data->sides.so_txt);
	printf("ea	: |%s|\n", data->sides.ea_txt);
	printf("we	: |%s|\n", data->sides.we_txt);
	printf("c	: |%s|\n", data->sides.c_txt);
	printf("f	: |%s|\n", data->sides.f_txt);
	return (EXIT_SUCCESS);
}