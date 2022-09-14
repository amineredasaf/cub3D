#include "../includes/cub3d.h"

void	ft_set_angle_pos(t_data *data, int x, int y, char flag)
{
	if (flag == 'N')
		data->player.angle = ft_convert_deg_rad(90);
	if (flag == 'S')
		data->player.angle = ft_convert_deg_rad(270);
	if (flag == 'W')
		data->player.angle = ft_convert_deg_rad(180);
	if (flag == 'E')
		data->player.angle = ft_convert_deg_rad(0);
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

void	ft_check_horiz(t_data *data, float angle, t_ray *ray)
{
	float	pointx;
	float	pointy;
	float	ystep;
	float	xstep;

	if (sin(angle) >= 0)
	{
		ystep = -64;
		pointy = floor(data->player.y / 64) * 64 - 1;
	}
	else
	{
		ystep = 64;
		pointy = floor(data->player.y / 64) * 64 + 64;
	}
	pointx = ((data->player.y - pointy) / tan(angle)) + data->player.x;
	xstep = 64 / tan(angle);
	if (cos(angle) < 0)
		xstep *= -1;
	if (floor(pointx / 64) < 0 || floor(pointx / 64) * 64 - 1 > ft_line_len(data, floor(pointy / 64)))
		ray->hdis = MAXFLOAT;
	else
	{
		while (!is_wall(data, floor(pointx / 64), floor(pointy / 64)))
		{
			pointx += xstep;
			pointy += ystep;
			if (floor(pointx / 64) < 0 || floor(pointx / 64) > ft_line_len(data, floor(pointy / 64) - 1))
			{
				ray->hdis = MAXFLOAT;
				break ;
			}
		}

	}
	if (floor(pointx / 64) >= 0 && floor(pointx / 64) <= ft_line_len(data, floor(pointy / 64) - 1))
	{
		ray->hdis = sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy)));
		ray->hendX = pointx;
		ray->hendY = pointy;
	}
}

void	ft_check_verti(t_data *data, float angle, t_ray *ray)
{
	float	pointx;
	float	pointy;
	float	ystep;
	float	xstep;

	if (cos(angle) >= 0)
	{
		pointx = floor(data->player.x / 64) * 64 + 64;
		xstep = 64;
	}
	else
	{
		pointx = floor(data->player.x / 64) * 64 - 1;
		xstep = -64;
	}
	pointy = data->player.y + (tan(angle) * (data->player.x - pointx));
	ystep = 64 * tan(angle);
	if (sin(angle) < 0)
		ystep *= -1;
	if (floor(pointy / 64) < 0 || floor(pointy / 64) >= data->map_s.n_lines - 1)
		ray->vdist = MAXFLOAT;
	else
	{
		while (!is_wall(data, floor(pointx / 64), floor(pointy / 64)))
		{
			pointx += xstep;
			pointy += ystep;
			if (floor(pointy / 64) < 0 || floor(pointy / 64) > data->map_s.n_lines - 1)
			{
				ray->vdist = MAXFLOAT;
				break ;
			}
		}
	}
	if (floor(pointy / 64) >= 0 && floor(pointy / 64) < data->map_s.n_lines - 1)
	{
		ray->vdist = sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy)));
		ray->vendX = pointx;
		ray->vendY = pointy;
	}
	// return (sqrt(((pointx - data->player.x) * (pointx - data->player.x)) + ((data->player.y - pointy) * (data->player.y - pointy))));
}

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

  for(int i = 0; i < 500; i++){
	mlx_pixel_put(data->minimap.mlx_ptr, data->minimap.win_ptr, x0, y0, data->floor.final_color);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}


void	ft_draw_ray(t_data *data, t_ray *ray, char flag)
{
	float	endx;
	float	endy;
	if (flag == 'h')
	{
		endx = ray->hendX;
		endy = ray->hendY;	
	}
	else
	{
		endx = ray->vendX;
		endy = ray->vendY;
	}
	line (data, data->player.x, data->player.y, (int) endx, (int) endy);
}

void	ft_execution(t_data *data)
{
	float	angle;
	t_ray	ray;
	int	i;

	i = 0;
	data->map_s.n_lines = ft_count_lines(data);
	angle = data->player.angle + ft_convert_deg_rad(30);
	while (i < 319)
	{
		ft_check_verti(data, angle, &ray);
		ft_check_horiz(data, angle, &ray);
		if (ray.hdis <= ray.vdist)
			ft_draw_ray(data, &ray, 'h');
		else
			ft_draw_ray(data, &ray, 'v');
		printf ("HOR : %f\n", ray.hdis);
		printf ("VER %f\n", ray.vdist);
		i++;
		angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
}