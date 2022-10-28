/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 22:07:48 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	destroy_win(int keycode, t_data *data)
{
	int	i;

	i = -1;
	(void)keycode;
	(void)data;
	ft_free_split(data->textures);
	ft_free_split(data->map_s.map);
	while (++i <= 3)
		mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	data.mlx_s.mlx_ptr = mlx_init();
	data.mlx_s.win_ptr = mlx_new_window(data.mlx_s.mlx_ptr, W_X, W_Y, "cube");
	data.mlx_s.frame_ptr = mlx_new_image(data.mlx_s.mlx_ptr, W_X, W_Y);
	data.mlx_s.mbuff = mlx_get_data_addr(data.mlx_s.frame_ptr, \
	&data.mlx_s.mbpp, &data.mlx_s.mllength, &data.mlx_s.mein);
	ft_get_starting_angle(&data);
	ft_execution(&data);
	key_pressed(&data);
	system("leaks cub3d");
	mlx_loop(data.mlx_s.mlx_ptr);
}
