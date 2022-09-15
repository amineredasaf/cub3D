#include "../includes/cub3d.h"

void	ft_set_angle_pos(t_data *data, int x, int y, char flag)
{
	if (flag == 'N')
		data->player.angle = M_PI_2;
	if (flag == 'S')
		data->player.angle = 3 * M_PI_2;
	if (flag == 'W')
		data->player.angle = M_PI;
	if (flag == 'E')
		data->player.angle = 0;
	data->player.x = (x * 64) + 32;
	data->player.y = (y * 64) + 32;
}

void	ft_get_starting_angle(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_s.map[++i])
	{
		j = -1;
		while (data->map_s.map[i][++j])
		{
			if (data->map_s.map[i][j] == 'N')
				ft_set_angle_pos(data, j, i,'N');				
			else if (data->map_s.map[i][j] == 'S')
				ft_set_angle_pos(data, j, i, 'S');		
			else if (data->map_s.map[i][j] == 'W')
				ft_set_angle_pos(data, j, i, 'W');
			else if (data->map_s.map[i][j] == 'E')
				ft_set_angle_pos(data, j, i, 'E');		
		}
	}
}

void	ft_update_view_angle(t_data *data, int flag)
{
	if (flag == ADD)
		data->player.angle += ft_convert_deg_rad(20);
	if (flag == SUB)
		data->player.angle -= ft_convert_deg_rad(20);
}

int		is_wall(t_data *data, int x, int y)
{
	if (data->map_s.map[y][x] == '0')
		return (0);
	else
		return (1);
}

float	ft_line_len(t_data *data, float y)
{
	int	x;
	int y1;

	x = 0;
	y1 = (int) y;
	while (data->map_s.map[y1][x] != '\0' && data->map_s.map[y1][x] != '\n')
		x++;
	return (x);
}

// void	ft_check_horiz(t_data *data, float angle, t_ray *ray)
// {
// 	float	pointx;
// 	float	pointy;
// 	float	ystep;
// 	float	xstep;

// 	if (sin(angle) >= 0)
// 	{
// 		ystep = -64;
// 		pointy = floor(data->player.y / 64) * 64 - 1;
// 	}
// 	else
// 	{
// 		ystep = 64;
// 		pointy = floor(data->player.y / 64) * 64 + 64;
// 	}
// 	pointx = ((data->player.y - pointy) / tan(angle)) + data->player.x;
// 	xstep = 64 / tan(angle);
// 	if (cos(angle) < 0)
// 		xstep *= -1;
// 	if (floor(pointx / 64) < 0
// 		|| floor(pointx / 64) * 64 - 1 > ft_line_len(data, floor(pointy / 64)))
// 		ray->hdis = MAXFLOAT;
// 	else
// 	{
// 		while (!is_wall(data, floor(pointx / 64), floor(pointy / 64)))
// 		{
// 			pointx += xstep;
// 			pointy += ystep;
// 			if (floor(pointx / 64) < 0 || floor(pointx / 64) > ft_line_len(data, floor(pointy / 64) - 1))
// 			{
// 				ray->hdis = MAXFLOAT;
// 				break ;
// 			}
// 		}
// 	}
// 	if (floor(pointx / 64) >= 0 && floor(pointx / 64) <= ft_line_len(data, floor(pointy / 64) - 1))
// 	{
// 		ray->hdis = sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy)));
// 		ray->hendX = pointx;
// 		ray->hendY = pointy;
// 	}
// }

// void	ft_check_verti(t_data *data, float angle, t_ray *ray)
// {
// 	float	pointx;
// 	float	pointy;
// 	float	ystep;
// 	float	xstep;

// 	if (cos(angle) >= 0)
// 	{
// 		pointx = floor(data->player.x / 64) * 64 + 64;
// 		xstep = 64;
// 	}
// 	else
// 	{
// 		pointx = floor(data->player.x / 64) * 64 - 1;
// 		xstep = -64;
// 	}
// 	pointy = data->player.y + (tan(angle) * (data->player.x - pointx));
// 	ystep = 64 * tan(angle);
// 	if (sin(angle) < 0)
// 		ystep *= -1;
// 	if (floor(pointy / 64) < 0 || floor(pointy / 64) >= data->map_s.n_lines - 1)
// 		ray->vdist = MAXFLOAT;
// 	else
// 	{
// 		while (!is_wall(data, floor(pointx / 64), floor(pointy / 64)))
// 		{
// 			pointx += xstep;
// 			pointy += ystep;
// 			if (floor(pointy / 64) < 0 || floor(pointy / 64) > data->map_s.n_lines - 1)
// 			{
// 				ray->vdist = MAXFLOAT;
// 				break ;
// 			}
// 		}
// 	}
// 	if (floor(pointy / 64) >= 0 && floor(pointy / 64) < data->map_s.n_lines - 1)
// 	{
// 		ray->vdist = sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy)));
// 		ray->vendX = pointx;
// 		ray->vendY = pointy;
// 	}
// 	return (sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy))));
// }

int	ft_count_lines(t_data *data)
{
	int i;

	i = 0;
	while (data->map_s.map[i])
		i++;
	return (i);
}

void line(t_data *data, int x0, int y0, int x1, int y1) {

  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;

  for(int i = 0; i < 1000; i++){
	mlx_pixel_put(data->minimap.mlx_ptr, data->minimap.win_ptr, x0, y0, data->floor.final_color);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}


void	ft_draw_ray(t_data *data, t_ray *ray)
{
	line (data, data->player.x, data->player.y, (int) ray->inter_x, (int) ray->inter_y);
}

void	ft_first_hor(t_data *data, t_ray *ray, float angle)
{
	// ray->inter_y = floor(data->player.y / 64) * 64 + (sin(angle) < 0) * 64 - (sin(angle) > 0) * 0.0001;
	// ray->ystep = 64 * ((sin(angle) < 0) - (sin(angle) > 0));
	if (sin(angle) >= 0)
	{
		ray->ystep = -64;
		ray->inter_y = floor(data->player.y / 64) * 64 - 1;
	}
	else
	{
		ray->ystep = 64;
		ray->inter_y = floor(data->player.y / 64) * 64 + 64;
	}
	ray->xstep = 64 / fabs(tan(angle));
	if (cos(angle) >= 0)
		ray->inter_x = data->player.x + fabs(fabs(data->player.y - ray->inter_y) / tan(angle));
	else
	{
		ray->inter_x = data->player.x - fabs(fabs(data->player.y - ray->inter_y) / tan(angle));
		ray->xstep = ray->xstep *= -1;
	}
	// ray->inter_x = data->player.x + fabs(fabs(data->player.y - ray->inter_y) / tan(angle)) * ((cos(angle) > 0) - (cos(angle) < 0));
	// printf("fabs(data->player.y - ray->inter_y)\t:\t%f\n/ tan(angle)\t:\t%f\ndata->player.x\t:\t%f\n",
	// 	fabs(data->player.y - ray->inter_y), fabs(data->player.y - ray->inter_y) / tan(angle), data->player.x);
	// ray->xstep = 64 / fabs(tan(angle));
	// if (cos(angle) < 0)
	// 	ray->xstep *= -1;
	// if (floor(ray->inter_x / 64) < 0
	// 	|| floor(ray->inter_x / 64) * 64 - 1 > ft_line_len(data, floor(ray->inter_y / 64)))
	// 	ray->dist = MAXFLOAT;
	// else
	ray->dist = fabs(data->player.x - ray->inter_x) / cos(angle);
}

void	ft_first_ver(t_data *data, t_ray *ray, float angle)
{
	// ray->inter_x = floor(data->player.x / 64) * 64 + (cos(angle) > 0) * 64 - (cos(angle) < 0) * 0.0001;
	// ray->xstep = 64 * ((cos(angle) > 0) - (cos(angle) < 0));
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
	ray->ystep = 64 * fabs(tan(angle));
	if (sin(angle) >= 0)
		ray->inter_y = data->player.y + fabs(tan(angle) * fabs(data->player.x - ray->inter_x));
	else
	{
		ray->inter_y = data->player.y - fabs(tan(angle) * fabs(data->player.x - ray->inter_x));
		ray->ystep *= -1;
	}
	// ray->inter_y = data->player.y + (tan(angle) * (data->player.x - ray->inter_x));
	// if (sin(angle) < 0)
	// 	ray->ystep *= -1;
	// if (floor(ray->inter_y / 64) < 0
	// 	|| floor(ray->inter_y / 64) >= data->map_s.n_lines - 1)
	// 	ray->dist = MAXFLOAT;
	// else
	ray->dist = fabs(data->player.x - ray->inter_x) / cos(angle);
}

void	ft_hor_check(t_data *data, t_ray *ray, float angle)
{
	if (floor(ray->inter_x / 64) < 0
		|| floor(ray->inter_x / 64) > ft_line_len(data, floor(ray->inter_y / 64)) - 1)
		ray->dist = MAXFLOAT;
	else
	{
		if (is_wall(data, floor(ray->inter_x / 64), floor(ray->inter_y / 64)))
		{
			ray->dist = fabs(data->player.x - ray->inter_x) / cos(angle);
			data->wall_hit = 1;
		}
		else
		{
			ray->inter_x += ray->xstep;
			ray->inter_y += ray->ystep;
		}
	}
}

void	ft_ver_check(t_data *data, t_ray *ray, float angle)
{
	if (floor(ray->inter_y / 64) < 0
		|| floor(ray->inter_y / 64) > data->map_s.n_lines - 1)
		ray->dist = MAXFLOAT;
	else
	{
		if (is_wall(data, floor(ray->inter_x / 64), floor(ray->inter_y / 64)))
		{
			ray->dist = fabs(data->player.x - ray->inter_x) / cos(angle);
			data->wall_hit = 1;
		}
		else
		{
			if (cos(angle) >= 0)
			ray->inter_x += ray->xstep + 1;
			ray->inter_y += ray->ystep;
		}
	}
}

t_ray	ft_cast_ray(t_data *data, float angle)
{
	t_ray	hor;
	t_ray	ver;

	data->wall_hit = 0;
	hor.dist = W_X * W_Y;
	ver.dist = W_X * W_Y;
	ft_first_hor(data, &hor, angle);
	// ft_first_ver(data, &ver, angle);
	// while (!data->wall_hit)
	// {
	// 	if (hor.dist <= ver.dist)
	// 		ft_hor_check(data, &hor, angle);
	// 	else
	// 		ft_ver_check(data, &ver, angle);
	// }
	if (hor.dist <= ver.dist)
		return (hor);
	else
		return (ver);
}

void	ft_execution(t_data *data)
{
	float	angle;
	int		i;
	t_ray	ray;

	i = 0;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle;
	// while (i < 19)
	// {
		ray = ft_cast_ray(data, data->player.angle);
		ft_draw_ray(data, &ray);
		// ft_check_verti(data, angle, &ray);
		// ft_check_horiz(data, angle, &ray);
		// if (ray.hdis <= ray.vdist)
		// 	ft_draw_ray(data, &ray, 'h');
		// else
		// 	ft_draw_ray(data, &ray, 'v');
		// printf ("HOR : %f\n", ray.hdis);
		// printf ("VER %f\n", ray.vdist);
		// i++;
		// angle -= ft_convert_deg_rad(ANGLE_STEP);
		// angle -= ft_convert_deg_rad(60 / 20);
	// }
}