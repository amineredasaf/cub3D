/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:38:25 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 00:38:26 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_first_ver(t_data *data, t_ray *ray, float angle)
{
	float	var;

	ray->ystep = fabs(64 * tan(angle));
	ray->xstep = 64;
	ray->inter_x = floor(data->player.x / 64) * 64 + 64;
	if (cos(angle) < 0)
	{
		ray->xstep = -64;
		ray->inter_x -= 64.0001;
	}
	var = tan(angle) * (data->player.x - ray->inter_x);
	ray->inter_y = data->player.y + var;
	if (sin(angle) >= 0)
		ray->ystep *= -1;
	if (floor(ray->inter_y / 64) < 0
		|| floor(ray->inter_y / 64) > data->map_s.n_lines - 1)
		ray->dist = MAXFLOAT;
	ray->dist = sqrtf((data->player.x - ray->inter_x)
			* (data->player.x - ray->inter_x)
			+ (data->player.y - ray->inter_y)
			* (data->player.y - ray->inter_y));
}

void	ft_ver_check(t_data *data, t_ray *ray)
{
	ray->dir = 'v';
	if (floor(ray->inter_y / 64) < 0
		|| floor(ray->inter_y / 64) > data->map_s.n_lines - 1)
		ray->dist = MAXFLOAT;
	else
	{
		if (is_wall(data, floor(ray->inter_x / 64), floor(ray->inter_y / 64)))
		{
			ray->dist = sqrtf((data->player.x - ray->inter_x)
					* (data->player.x - ray->inter_x)
					+ (data->player.y - ray->inter_y)
					* (data->player.y - ray->inter_y));
			data->wall_hit_ver = 1;
		}
		else
		{
			ray->inter_x += ray->xstep;
			ray->inter_y += ray->ystep;
		}
	}
}
