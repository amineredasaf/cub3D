/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:12:57 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 14:12:58 by rsaf             ###   ########.fr       */
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
		destroy_win(53, data);
	return (EXIT_SUCCESS);
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
	t_keys	key;

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
	return (0);
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
