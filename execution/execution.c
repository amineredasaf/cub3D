
#include "../includes/cub3d.h"

void	ft_draw_f_c(t_data *data)
{
	int	i;
	// int	j;
	// void	*ptr;
	// void	*ptr2;

	i = 0;
	insert_img_buffer(data, W_X/2, W_X/2, W_X/2);
	insert_img_buffer(data, W_X/2, W_X/2, W_X/2);
}

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
		if (ver.dist <= ver.dist && !data->wall_hit_ver)
			ft_ver_check(data, &ver);
	}
	if (hor.dist <= ver.dist)
	{
		hor.dir = 'h';
		return (hor);
	}
	else
	{
		ver.dir = 'v';
		return (ver);
	}
}

void	ft_execution(t_data *data)
{
	float	angle;
	float	projected_wall;
	int		i;
	int		ver;
	int		hor;
	float	real;
	double		offset_x;
	double		offset_y;
	t_ray	ray;

	i = -1;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	int from = 0;
	int b = 0;
	double	k = 0;
	ver = 0;
	hor = 0;
	data->mlx_s.img2_ptr = mlx_xpm_file_to_image(data->mlx_s.mlx_ptr, data->sides.no_txt, &data->mlx_s.img_wid, &data->mlx_s.img_hie);
	data->mlx_s.img_buff2 = (int *)mlx_get_data_addr(data->mlx_s.img2_ptr, &data->mlx_s.bpp2, &data->mlx_s.llength2, &data->mlx_s.ein2);
	while (++i < 1000)
	{
		ray = ft_cast_ray(data, angle);
		if (ray.dir == 'v')
			offset_x = (ray.inter_y / 64);
		if (ray.dir == 'h')
			offset_x = (ray.inter_x / 64);
		offset_x = offset_x - floor(offset_x);
		offset_x *= data->mlx_s.img_wid;
		real = ray.dist * cos(angle - data->player.angle);
		projected_wall = floor((64 / real) * 277);
		from = (W_Y - projected_wall) / 2;
		k = (projected_wall / 2) - (W_Y / 2);
		b = -1;
		while (++b < from)
			insert_img_buffer(data, i, b, data->ceiling.final_color);
		while (b >= from && b < from + projected_wall)
		{
			offset_y = (b + k) * (data->mlx_s.img_hie / projected_wall);
			offset_y = floor(offset_y);
			offset_y *= data->mlx_s.img_wid;
			insert_img_buffer(data, i, b, data->mlx_s.img_buff2[(int)offset_x + (int)offset_y]);
			b++;
		}
		while (b >= from + projected_wall && b < W_Y)
		{
			insert_img_buffer(data, i, b, data->floor.final_color);
			b++;
		}
		angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
	put_on_win(data, data->mlx_s.img_ptr, 0, 0);
}