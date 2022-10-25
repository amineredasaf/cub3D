/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/25 14:51:41 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// this func find which key and move to the right direction
// |	0 : A	|	2 : D	|	1 : S	|	13 : W	|
int	key_detector(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 0)
		data->key_flags.move_left = 1;
	if (keycode == 1)
		data->key_flags.move_backward = 1;
	if (keycode == 2)
		data->key_flags.move_right = 1;
	if (keycode == 13)
		data->key_flags.move_forward = 1;
	if (keycode == 123)
		data->key_flags.rotate_left = 1;
	if (keycode == 124)
		data->key_flags.rotate_right = 1;
	if (keycode == 53)
		exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	destroy_win(int keycode, t_data *data)
{
	int	i;

	i = -1;
	(void)keycode;
	(void)data;
	// mlx_destroy_image(data->mlx_s.mlx_ptr, data->mlx_s.frame_ptr);
	// while (++i <= 3)
	// 	mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
	exit (EXIT_SUCCESS);
}

int	key_released(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 0)
		data->key_flags.move_left = 0;
	if (keycode == 1)
		data->key_flags.move_backward = 0;
	if (keycode == 2)
		data->key_flags.move_right = 0;
	if (keycode == 13)
		data->key_flags.move_forward = 0;
	if (keycode == 123)
		data->key_flags.rotate_left = 0;
	if (keycode == 124)
		data->key_flags.rotate_right = 0;
	if (keycode == 53)
		destroy_win(53, data);
	return (EXIT_SUCCESS);
}


int	update_frame(t_data *data)
{
	t_keys key;

	key = data->key_flags;
	if (key.move_left == 1)
		move_left(data);
	if (key.move_right == 1)
		move_right(data);
	if (key.move_backward == 1)
		move_backward(data);
	if (key.move_forward == 1)
		move_forward(data);
	if (key.rotate_left == 1)
		rotate_player(data, LEFT);
	if (key.rotate_right == 1)
		rotate_player(data, RIGHT);
	return 0;
}
// this func waitng for key pressed to call the right action
int	key_pressed(t_data *data)
{
	mlx_hook(data->mlx_s.win_ptr, 2, 1L << 2, key_detector, data);
	mlx_hook(data->mlx_s.win_ptr, 3, 1L << 3, key_released, data);
	mlx_hook(data->mlx_s.win_ptr, 17, 1L << 0, destroy_win, data);
	mlx_loop_hook(data->mlx_s.mlx_ptr, update_frame, data);
	return (EXIT_SUCCESS);
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
	data.mlx_s.mbuff = mlx_get_data_addr(data.mlx_s.frame_ptr, &data.mlx_s.mbpp, &data.mlx_s.mllength, &data.mlx_s.mein);
	ft_get_starting_angle(&data);
	ft_execution(&data);
	key_pressed(&data);
	mlx_loop(data.mlx_s.mlx_ptr);
}
