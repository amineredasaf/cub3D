#include "../includes/cub3d.h"

float	ft_convert_deg_rad(float deg)
{
	return (deg * (M_PI / 180));
}

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

float	ft_line_len(t_data *data, float y)
{
	int	x;
	int y1;

	x = 0;
	y1 = (int) y;
	if (y >= 0)
	{
		while (data->map_s.map[y1] && data->map_s.map[y1][x] != '\0' && data->map_s.map[y1][x] != '\n')
			x++;
	}
	return (x);
}


int	ft_count_lines(t_data *data)
{
	int i;

	i = 0;
	while (data->map_s.map[i])
		i++;
	return (i);
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
	if (data->map_s.map[y][x] != '1')
		return (0);
	else
		return (1);
}
