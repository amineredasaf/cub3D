/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:43:38 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/02 21:56:19 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int mlx_initialization(t_data *data)
{
	t_mlx   *mlx_s;

	mlx_s->name = ft_strdup("Cub3d");
	mlx_s->mlx_ptr = mlx_init();
	mlx_s->win_ptr = mlx_new_window(mlx_s->mlx_ptr, 1200, 1200, mlx_s->name);
	
	mlx_loop(mlx_s->mlx_ptr);
	return (EXIT_SUCCESS);
}