/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:01:10 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/29 02:39:27 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_issides(char *line, char a, char b)
{
	if (line && line[0] == a && line[1] == b && line[2] == ' '
		&& (line[3] >= 'a' && line[3] <= 'z'))
		return (TRUE);
	return (FAlSE);
}

int	ft_check_sides(char *line, int x)
{	
	if (ft_issides(line, 'N', 'O'))
		printf("NO\n");
	else if (ft_issides(line, 'S', 'O'))
		printf("SO\n");
	else if (ft_issides(line, 'W', 'E'))
		printf("WE\n");
	else if (ft_issides(line, 'E', 'A'))
		printf("EA\n");
	return (EXIT_SUCCESS);
}

int ft_parse_textures(t_data *data)
{
	char *line;
	int	x;

	x = 0;
	while (data->file_content && data->file_content[x])
	{
		line = data->file_content[x];
		if (line && line[0] != ' ' && line[0] != '\n' && line[0] != '\0')
			ft_check_sides(line, x);
		line = NULL;
		x++;
	}
	return (EXIT_SUCCESS);
}