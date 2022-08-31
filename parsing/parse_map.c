/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:31:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/31 13:38:48 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parse_map(t_data *data)
{
	int	x;

	x = 0;
	while (data->file_content[x])
		// printf("%s", data->file_content[x++]);
		x++;
	return (EXIT_SUCCESS);
}