/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/28 15:20:07 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	if (ft_parsing(&data))
		return (1);
	return (0);
}