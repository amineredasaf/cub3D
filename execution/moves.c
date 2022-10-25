/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:32:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/25 14:48:37 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_data *data, int flag)
{
	int		i = -1;
	t_keys key;

	key = data->key_flags;
	if (key.rotate_left == 1 || key.rotate_right == 1)
	{
		while (++i <= 3)
			mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
		if (flag == RIGHT)
			data->player.angle -= ft_convert_deg_rad(R_S);
		else if (flag == LEFT)
			data->player.angle += ft_convert_deg_rad(R_S);
		mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
		ft_execution(data);
	}
}

void	move_forward(t_data *data)
{
	int		i = -1;
	float	x_change;
	float	y_change;

	t_keys key;

	key = data->key_flags;
	x_change = data->player.x + cos(data->player.angle) * M_S;
	y_change = data->player.y - sin(data->player.angle) * M_S;
	if (key.move_forward == 1)
	{
		if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != '0'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'S'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'N'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W')
			return ;
		while (++i <= 3)
			mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
		mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
		data->player.x = x_change;
		data->player.y = y_change;
		ft_execution(data);
	}
}

void	move_backward(t_data *data)
{
	int		i = -1;
	float	x_change;
	float	y_change;

	t_keys key;

	key = data->key_flags;
	x_change = data->player.x - cos(data->player.angle) * M_S;
	y_change = data->player.y + sin(data->player.angle) * M_S;
	if (key.move_backward == 1)
	{
		if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != '0'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'S'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'N'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W')
			return ;
		while (++i <= 3)
			mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
		mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
		data->player.x = x_change;
		data->player.y = y_change;
		ft_execution(data);
	}
}

void	move_left(t_data *data)
{
	int		i = -1;
	float	x_change = 0;
	float	y_change = 0;

	t_keys key;

	key = data->key_flags;
	x_change = data->player.x - cos((M_PI / 2) - data->player.angle) * M_S;
	y_change = data->player.y - sin((M_PI / 2) - data->player.angle) * M_S;
	if (key.move_left == 1)
	{
		if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != '0'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'S'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'N'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W')
			return ;
		while (++i <= 3)
			mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
		mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
		data->player.x = x_change;
		data->player.y = y_change;
		ft_execution(data);
	}
}

void	move_right(t_data *data)
{
	int		i = -1;
	float	x_change = 0;
	float	y_change = 0;
	t_keys key;

	key = data->key_flags;
	x_change = data->player.x + cos((M_PI / 2) - data->player.angle) * M_S;
	y_change = data->player.y + sin((M_PI / 2) - data->player.angle) * M_S;
	if (key.move_right == 1)
	{
		if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != '0'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'S'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'N'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W'
			&& data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] != 'W')
			return ;
		while (++i <= 3)
			mlx_destroy_image(data->mlx_s.mlx_ptr, data->side[i].img_ptr);
		mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
		data->player.x = x_change;
		data->player.y = y_change;
		ft_execution(data);
	}
}