/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:38:33 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/21 12:48:32 by rsaf             ###   ########.fr       */
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

	pixel = (j * lenght) + (i * data->mlx_s.bpp2 / 8);
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
	data->mlx_s.img2_ptr = mlx_xpm_file_to_image(data->mlx_s.mlx_ptr, data->sides.no_txt, &data->mlx_s.img_wid, &data->mlx_s.img_hie);
	data->mlx_s.img_buff2 = mlx_get_data_addr(data->mlx_s.img2_ptr, &data->mlx_s.bpp2, &data->mlx_s.llength2, &data->mlx_s.ein2);
	if (!data->mlx_s.img_buff2)
		exit(ft_print_error("Mlx Error"));
	// printf(">>> %d\n",data->mlx_s.llength2);exit(0);
	while (++i < W_X)
	{
		ray = ft_cast_ray(data, angle);
		// offset_x -= floor(offset_x);
		// offset_x *= data->mlx_s.img_wid;
		real = ray.dist * cos(angle - data->player.angle);
		projected_wall = floor((64 / real) * 277);
		if (ray.dir == 'v')
			offset_x = fmod(ray.inter_y, 64) * data->mlx_s.img_wid / BLOCK_W;
		if (ray.dir == 'h')
			offset_x = fmod(ray.inter_x, 64) * data->mlx_s.img_wid / BLOCK_W;
		// offset_x = ((fmod(ray.inter_x, BLOCK_W) * data->mlx_s.img_wid) / BLOCK_W); 
		// printf("x =  %f , y =  %d\n",ray.inter_x);
		from = (W_Y - projected_wall) / 2 > 0 ? (W_Y - projected_wall) / 2 : 0;
		k = from + projected_wall;
		if (k > W_Y)
			k = W_Y;
		b = -1;
		while (++b <= from)
			insert_img_buffer(data, i, b, data->ceiling.final_color);
		while (b < k)
		{
			offset_y = (fmod(b - (W_Y/2 - projected_wall/2), projected_wall) * (data->mlx_s.img_hie / projected_wall));
			// offset_y = (b + k) * (data->mlx_s.img_hie / projected_wall);
			// offset_y = floor(offset_y);
			// offset_y *= data->mlx_s.img_wid;
			
			// int	pixel = (offset_y * data->mlx_s.llength2) + (offset_x * 8);



			// insert_img_buffer(data, i, b, data->mlx_s.img_buff2[(int)offset_x + (int)offset_y]);
			insert_img_buffer(data, i, b, color_convert(data, data->mlx_s.img_buff2, data->mlx_s.llength2, offset_x, offset_y));
			b++;
		}
		while (b < W_Y)
		{
			insert_img_buffer(data, i, b, data->floor.final_color);
			b++;
		}
		angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
	put_on_win(data, data->mlx_s.img_ptr, 0, 0);
	return 0;
}
