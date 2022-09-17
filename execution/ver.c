#include "../includes/cub3d.h"

void	ft_first_ver(t_data *data, t_ray *ray, float angle)
{
	ray->ystep = 64 * tan(angle);
	if (cos(angle) >= 0)
	{
		ray->xstep = 64;
		ray->inter_x = floor(data->player.x / 64) * 64 + 64;
	}
	else
	{
		ray->xstep = -64;
		ray->inter_x = floor(data->player.x / 64) * 64 - 0.0001;
	}
	if (sin(angle) >= 0)
	{
		ray->inter_y = data->player.y - fabs(tan(angle) * fabs(data->player.x - ray->inter_x));
		ray->ystep *= -1;
	}
	else
		ray->inter_y = data->player.y + fabs(tan(angle) * fabs(data->player.x - ray->inter_x));
	if (floor(ray->inter_y / 64) < 0
		|| floor(ray->inter_y / 64) >= data->map_s.n_lines - 1)
		ray->dist = MAXFLOAT;
	// ray->dist = fabs(data->player.x - ray->inter_x) / cos(angle);
	ray->dist = sqrtf((data->player.x - ray->inter_x) * (data->player.x - ray->inter_x) + (data->player.y - ray->inter_y) * (data->player.y - ray->inter_y));
}

void	ft_ver_check(t_data *data, t_ray *ray)
{
	if (floor(ray->inter_y / 64) < 0
		|| floor(ray->inter_y / 64) > data->map_s.n_lines - 1)
		ray->dist = MAXFLOAT;
	else
	{
		if (is_wall(data, floor(ray->inter_x / 64), floor(ray->inter_y / 64)))
		{
			ray->dist = sqrtf((data->player.x - ray->inter_x) * (data->player.x - ray->inter_x) + (data->player.y - ray->inter_y) * (data->player.y - ray->inter_y));
			data->wall_hit_ver = 1;
		}
		else
		{
			ray->inter_x += ray->xstep + 1;
			ray->inter_y += ray->ystep;
		}
	}
}