#include "../includes/cub3d.h"

int	ft_can_move(t_data *data, float x, float y)
{
	if (data->map_s.map[(int)floor(y / 64)][(int)floor(x / 64)] == '1'
			|| data->map_s.map[(int)floor(y / 64)][(int)floor(x / 64)] == '\n'
			|| data->map_s.map[(int)floor(y / 64)][(int)floor(x / 64)] == '\0')
		return (0);
	return (1);
}

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
				ft_set_angle_pos(data, j, i, 'N');
			else if (data->map_s.map[i][j] == 'S')
				ft_set_angle_pos(data, j, i, 'S');
			else if (data->map_s.map[i][j] == 'W')
				ft_set_angle_pos(data, j, i, 'W');
			else if (data->map_s.map[i][j] == 'E')
				ft_set_angle_pos(data, j, i, 'E');
		}
	}
}
