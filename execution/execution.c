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
	if (data->map_s.map[x][y] == '1')
		return (1);
	else
		return (0);
}

void	ft_check_horiz(t_data *data, float angle)
{
	float	pointx;
	float	pointy;
	float	ystep;
	float	xstep;

	if (sin(angle) >= 0)
	{
		ystep = 64;
		pointy = floor(data->player.y / 64) - 1;
	}
	else if (sin(angle) < 0)
	{
		ystep = -64;
		pointy = floor(data->player.y / 64) + 64;
	}
	pointx = ((data->player.y - pointy) / tan(angle)) + data->player.x;
	xstep = 64 / tan(angle);
	while (!is_wall(data, pointx / 64, pointy / 64))
	{
		pointx += xstep;
		pointy += ystep;
	}
}

void	ft_check_verti(t_data *data, float angle)
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
	else if (cos(angle) < 0)
	{
		pointx = floor(data->player.x / 64) * 64 + 64;
		xstep = -64;
	}
	pointy = (tan(angle) * data->player.x - pointx) + pointy;
	ystep = 64 * tan(angle);
	while (!is_wall(data, pointx / 64, pointy / 64))
	{
		pointx += xstep;
		pointy += ystep;
	}
}

void	ft_execution(t_data *data)
{
	ft_get_starting_angle(data);
	float	angle;
	int	i;

	i = 0;
	angle = data->player.angle + ft_convert_deg_rad(30);
	while (i < 319)
	{
		ft_check_horiz(data, ft_convert_deg_rad(angle));
		ft_check_verti(data, ft_convert_deg_rad(angle));
		i++;
		angle -= ft_convert_deg_rad(ANGLE_STEP);
	}
}