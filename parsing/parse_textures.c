/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:01:10 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/29 04:52:44 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func compare sides and [ NO - SO - WE - EA]
int	ft_issides(char *line, char a, char b)
{
	if (line && line[0] == a && line[1] == b && line[2] == ' '
		&& (line[3] >= 'a' && line[3] <= 'z'))
		return (TRUE);
	return (FAlSE);
}

// this func alloact texture data in our struct. beta version could be better
int	ft_init_sides(t_data *data, char *line, int flag)
{
	int	len;

	if  (flag == S_NO && data->sides.n_no < 1)
		data->sides.no_txt = ft_strdup(&line[3]);
	else if (flag == S_SO && data->sides.n_so < 1)
		data->sides.so_txt = ft_strdup(&line[3]);
	else if  (flag == S_WE && data->sides.n_we < 1)
		data->sides.we_txt = ft_strdup(&line[3]);
	else if (flag == S_EA && data->sides.n_ea < 1)
		data->sides.ea_txt = ft_strdup(&line[3]);
	return (EXIT_SUCCESS);
}

// this func looks for sides and init them
int	ft_check_sides(t_data *data, char *line, int x)
{
	if (ft_issides(line, 'N', 'O'))
		ft_init_sides(data, line, S_NO);
	else if (ft_issides(line, 'S', 'O'))
		ft_init_sides(data, line, S_SO);
	else if (ft_issides(line, 'W', 'E'))
		ft_init_sides(data, line, S_WE);
	else if (ft_issides(line, 'E', 'A'))
		ft_init_sides(data, line, S_EA);
	return (EXIT_SUCCESS);
}

// this func looks for texture from the conf file and parse them
int	ft_parse_textures(t_data *data)
{
	char *line;
	int	x;

	x = 0;
	data->sides.n_ea = 0;
	data->sides.n_no = 0;
	data->sides.n_so = 0;
	data->sides.n_we = 0;
	while (data->file_content && data->file_content[x])
	{
		line = data->file_content[x];
		if (line && line[0] != ' ' && line[0] != '\n' && line[0] != '\0')
			ft_check_sides(data, line, x);
		line = NULL;
		x++;
	}
	printf("- EA: %s\n",data->sides.ea_txt);
	printf("- SO: %s\n",data->sides.so_txt);
	printf("- NO: %s\n",data->sides.no_txt);
	printf("- WE: %s\n",data->sides.we_txt);
	return (EXIT_SUCCESS);
}