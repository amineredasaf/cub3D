
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
	float	real_distance;
	int		i;
	t_ray	ray;

	i = 0;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	while (i < 319)
	{
		ray = ft_cast_ray(data, angle);
		real_distance = ray.dist * fabs(cos(angle));
		// ft_draw_ray(data, &ray);
		projected_wall = floor((64 / ray.dist) * 277);
		// (wind high - project wall) / 2;
		data->minimap.img_ptr = insert_img_buffer(data, 500, W_X/320, projected_wall);
		put_on_win(data, data->minimap.img_ptr, i*(W_X/320), (W_Y - projected_wall) / 2);
		// printf("y = %f -- x = %d\n", projected_wall, W_X/320);

		i++;
		angle -= ft_convert_deg_rad(ANGLE_STEP);
		// angle -= ft_convert_deg_rad(60 / 20);
	}
}