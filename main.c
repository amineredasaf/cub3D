/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/29 00:46:36 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	return (0);
}