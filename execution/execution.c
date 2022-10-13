
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
		return (hor);
	else
		return (ver);
}

void	ft_execution(t_data *data)
{
	float	angle;
	float	projected_wall;
	int		i;
	t_ray	ray;

	i = 0;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	// ft_draw_f_c(data);
	int from = 0;
	int b = 0;
	while (i < 500)
	{
		ray = ft_cast_ray(data, angle);
		// ft_draw_ray(data, &ray);
		projected_wall = floor((64 / ray.dist) * 277);
		from = (W_Y - projected_wall) / 2;
		b = 0;
		while (b < from)
		{
			insert_img_buffer(data, i, b, 0xFF1053);
			b++;
		}
		while (b >= from && b < from + projected_wall)
		{
			insert_img_buffer(data, i, b, 65280);
			b++;
		}
		while (b >= from + projected_wall && b < W_Y)
		{
			insert_img_buffer(data, i, b, 16766720);
			b++;
		}
		i++;
		angle -= ft_convert_deg_rad(ANGLE_STEP);
		// angle -= ft_convert_deg_rad(60 / 20);
	}
	put_on_win(data, data->minimap.img_ptr, 0, 0);
}