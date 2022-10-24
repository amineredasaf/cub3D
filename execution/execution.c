/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:38:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/24 10:56:14 by rsaf             ###   ########.fr       */
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
	while ((!data->wall_hit_hor && ver.dist >= hor.dist) || (!data->wall_hit_ver && hor.dist >= ver.dist))
	{
		if (hor.dist <= ver.dist && !data->wall_hit_hor)
			ft_hor_check(data, &hor);
		if (ver.dist < hor.dist && !data->wall_hit_ver)
			ft_ver_check(data, &ver);
	}
	if (hor.dist <= ver.dist)
		return (hor);
	else
		return (ver);
}


int	color_convert(t_data *data, char *buff, int lenght, int i, int j)
{
	int	pixel;
	int	color = 0;

	pixel = (j * lenght) + (i * data->side.bpp/ 8);
	if (pixel > 0)
	{
		color = buff[pixel + 0];
		color += buff[pixel + 1] << 8;
		color += buff[pixel + 2] << 16;
	}
	return (color);
}

int	ft_execution(t_data *data)
{
	int	offset_x;
	int	offset_y;
	double	k;
	float	angle;
	float	projected_wall;
	float	real;
	int		i;
	int		ver;
	int		hor;
	int		from;
	double		b;
	t_ray	ray;

	i = -1;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	from = 0;
	b = 0;
	k = 0;
	ver = 0;
	hor = 0;
	data->side.img_ptr = mlx_xpm_file_to_image(data->mlx_s.mlx_ptr, data->sides.no_txt, &data->side.img_wid, &data->side.img_hie);
	data->mlx_s.img_buff2 = mlx_get_data_addr(data->side.img_ptr, &data->side.bpp, &data->side.llength, &data->side.ein);
	if (!data->mlx_s.img_buff2)
		exit(ft_print_error("Mlx Error"));
	while (++i < W_X)
	{
		ray = ft_cast_ray(data, angle);
		real = ray.dist * cos(angle - data->player.angle);
		projected_wall = floor((64 / real) * 277);
		if (ray.dir == 'v')
			offset_x = fmod(ray.inter_y, 64) * data->side.img_wid / BLOCK_W;
		if (ray.dir == 'h')
			offset_x = fmod(ray.inter_x, 64) * data->side.img_wid / BLOCK_W;
		from = (W_Y - projected_wall) / 2 > 0 ? (W_Y - projected_wall) / 2 : 0;
		k = from + projected_wall;
		if (k > W_Y)
			k = W_Y;
		b = -1;
		while (++b <= from)
			insert_img_buffer(data, i, b, data->ceiling.final_color);
		while (b < k)
		{
			offset_y = (fmod(b - (W_Y/2 - projected_wall/2), projected_wall) * (data->side.img_hie / projected_wall));
			insert_img_buffer(data, i, b, color_convert(data, data->mlx_s.img_buff2, data->side.llength, offset_x, offset_y));
			b++;
		}
		while (b < W_Y)
		{
			insert_img_buffer(data, i, b, data->floor.final_color);
			b++;
		}
		angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
	put_on_win(data, data->mlx_s.frame_ptr, 0, 0);
	mlx_destroy_image(data->mlx_s.mlx_ptr, data->side.img_ptr);
	return 0;
}
