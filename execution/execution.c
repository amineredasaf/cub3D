
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
	printf("hor [%f]\n", hor.dist);
	printf("ver [%f]\n", ver.dist);
	if (hor.dist <= ver.dist)
		return (hor);
	else
		return (ver);
	// if (data->wall_hit_hor)
	// 	return (hor);
	// else if (data->wall_hit_ver)
	// 	return (ver);
	// return (hor);
}

void	ft_execution(t_data *data)
{
	float	angle;
	int		i;
	t_ray	ray;

	i = 0;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	while (i < 319)
	{
		// HERE
		ray = ft_cast_ray(data, angle);
		// HERE
		ft_draw_ray(data, &ray);
		i++;
		angle -= ft_convert_deg_rad(ANGLE_STEP);
		// angle -= ft_convert_deg_rad(60 / 20);
	}
}