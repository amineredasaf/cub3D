#include "../includes/cub3d.h"

void	ft_first_hor(t_data *data, t_ray *ray, float angle)
{
	float	var;

	ray->xstep = 64 / fabs(tan(angle));
	ray->ystep = 64;
	ray->inter_y = floor(data->player.y / 64) * 64 + 64;
	if (sin(angle) >= 0)
	{
		ray->ystep *= -1;
		ray->inter_y -= 64.0001;
	}
	var = (data->player.y - ray->inter_y) / tan(angle);
	ray->inter_x = data->player.x + var;
	if (cos(angle) < 0)
		ray->xstep *= -1;
	if (floor(ray->inter_x / 64) < 0
		|| floor(ray->inter_x / 64) * 64 - 1
		> ft_line_len(data, floor(ray->inter_y / 64)))
		ray->dist = MAXFLOAT;
	ray->dist = sqrtf((data->player.x - ray->inter_x)
			* (data->player.x - ray->inter_x)
			+ (data->player.y - ray->inter_y)
			* (data->player.y - ray->inter_y));
}

void	ft_hor_check(t_data *data, t_ray *ray)
{
	if (floor(ray->inter_x / 64) < 0
		|| floor(ray->inter_x / 64)
		> ft_line_len(data, floor(ray->inter_y / 64)) - 1)
		ray->dist = MAXFLOAT;
	else
	{
		if (is_wall(data, floor(ray->inter_x / 64), floor(ray->inter_y / 64)))
		{
			ray->dist = sqrtf((data->player.x - ray->inter_x)
					* (data->player.x - ray->inter_x)
					+ (data->player.y - ray->inter_y)
					* (data->player.y - ray->inter_y));
			data->wall_hit_hor = 1;
		}
		else
		{
			ray->inter_x += ray->xstep;
			ray->inter_y += ray->ystep;
		}
	}
}
