/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:38:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 00:44:53 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray	ft_cast_ray(t_data *data, float angle)
{
	t_ray	hor;
	t_ray	ver;

	data->wall_hit_ver = 0;
	data->wall_hit_hor = 0;
	hor.dist = W_X * W_Y;
	ver.dist = W_X * W_Y;
	ft_first_hor(data, &hor, angle);
	ft_first_ver(data, &ver, angle);
	while (((!data->wall_hit_hor && ver.dist >= hor.dist) || \
	(!data->wall_hit_ver && hor.dist >= ver.dist))
		&& (hor.dist < MAXFLOAT || ver.dist < MAXFLOAT))
	{
		if (hor.dist <= ver.dist && !data->wall_hit_hor)
			ft_hor_check(data, &hor);
		if (ver.dist <= hor.dist && !data->wall_hit_ver)
			ft_ver_check(data, &ver);
	}
	if (hor.dist <= ver.dist)
		return (hor);
	else
		return (ver);
}

void	get_offset_x_texture(t_data *data)
{
	if (data->exe.ray.dir == 'v')
	{
		data->exe.offset_x = fmod(data->exe.ray.inter_y, 64)
			* data->side[data->exe.idx].img_wid / BLOCK_W;
		if (cos(data->exe.angle) >= 0)
			data->exe.idx = EA;
		else
			data->exe.idx = WE;
	}
	if (data->exe.ray.dir == 'h')
	{
		data->exe.offset_x = fmod(data->exe.ray.inter_x, 64)
			* data->side[data->exe.idx].img_wid / BLOCK_W;
		if (sin(data->exe.angle) >= 0)
			data->exe.idx = NO;
		else
			data->exe.idx = SO;
	}
}

void	ft_initialize_exe(t_data *data)
{
	data->exe.angle = data->player.angle + H_FOV;
	data->exe.from = 0;
	data->exe.b = 0;
	data->exe.k = 0;
	data->exe.ver = 0;
	data->exe.hor = 0;
	data->exe.idx = 0;
}

void	ft_rendering(t_data *data)
{
	data->exe.b = -1;
	while (++data->exe.b <= data->exe.from)
		insert_img_buffer(data, data->exe.i, data->exe.b,
			data->ceiling.final_color);
	while (data->exe.b < data->exe.k)
	{
		data->exe.offset_y = (fmod(data->exe.b \
		- (W_Y / 2 - data->exe.projected_wall / 2), \
		data->exe.projected_wall) \
		* (data->side[data->exe.idx].img_hie / data->exe.projected_wall));
		insert_img_buffer(data, data->exe.i, data->exe.b, \
		color_convert(data, data->side[data->exe.idx].img_buff, \
		data->side[data->exe.idx].llength));
		data->exe.b++;
	}
	while (data->exe.b < W_Y)
	{
		insert_img_buffer(data, data->exe.i, data->exe.b, \
		data->floor.final_color);
		data->exe.b++;
	}
}

int	ft_execution(t_data *data)
{
	data->exe.i = -1;
	ft_initialize_exe(data);
	prepare_textures(data);
	while (++data->exe.i < W_X)
	{
		data->exe.ray = ft_cast_ray(data, data->exe.angle);
		data->exe.real = data->exe.ray.dist \
		* cos(data->exe.angle - data->player.angle);
		data->exe.projected_wall = floor((64 / data->exe.real) * 277);
		get_offset_x_texture(data);
		if ((W_Y - data->exe.projected_wall) / 2)
			data->exe.from = (W_Y - data->exe.projected_wall) / 2;
		else
			data->exe.from = 0;
		data->exe.k = data->exe.from + data->exe.projected_wall;
		if (data->exe.k > W_Y)
			data->exe.k = W_Y;
		ft_rendering(data);
		data->exe.angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
	put_on_win(data, data->mlx_s.frame_ptr, 0, 0);
	mlx_destroy_image(data->mlx_s.mlx_ptr, data->mlx_s.frame_ptr);
	return (0);
}
