/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:32:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/19 08:37:15 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_data *data, int flag)
{
	if (flag == RIGHT)
		data->player.angle -= ft_convert_deg_rad(R_S);
	else if (flag == LEFT)
		data->player.angle += ft_convert_deg_rad(R_S);
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
	ft_execution(data);
}

void	move_forward(t_data *data)
{
	float	x_change;
	float	y_change;

	x_change = data->player.x + cos(data->player.angle) * M_S;
	y_change = data->player.y - sin(data->player.angle) * M_S;
	if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] == '1')
		return ;
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
	data->player.x = x_change;
	data->player.y = y_change;
	ft_execution(data);
}

void	move_backward(t_data *data)
{
	float	x_change;
	float	y_change;

	x_change = data->player.x - cos(data->player.angle) * M_S;
	y_change = data->player.y + sin(data->player.angle) * M_S;
	if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] == '1')
		return ;
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
	data->player.x -= cos(data->player.angle) * M_S;
	data->player.y += sin(data->player.angle) * M_S;
	ft_execution(data);
}