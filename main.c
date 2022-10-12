/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/12 05:38:33 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->minimap.buff + (y * data->minimap.llength + x * (data->minimap.bpp / 8));
	*(unsigned int*)dst = color;
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	t_mlx map;

	map = data->minimap;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x, y);
}

// for testing some ideas
int	draw_minimap(t_data *data)
{
	int		y;
	int		x;
	// int		len;
	char	**map;

	y = 0;
	map = data->map_s.map;
	// data->minimap.play_ptr = insert_img_buffer(data, 0x12FF00, 20, 64);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || ft_isspace(map[y][x]))
				put_on_win(data, data->minimap.wall_ptr, x * 64, y * 64);
			// else if (map[y][x] == 'N')
			// {
			// 	data->minimap.x = x;
			// 	data->minimap.y = y;
			// 	put_on_win(data, data->minimap.play_ptr, x * 20, y * 20);
			// }
			x++;
		}
		y++;
	}

// printf("data->player.angle\t:\t%f\n", (data->player.angle * 180) / M_PI );

	// line(data, 0, 0, 150, 150);
	return (EXIT_SUCCESS);
}

// this func update the map and draw it again.
int	update_minimap(t_data *data, int x, int y)
{
	int old_x;
	int	old_y;

	old_x = data->minimap.x;
	old_y = data->minimap.y;
	if (data->map_s.map[old_y + y][old_x + x] != '1')
	{
		mlx_clear_window(data->minimap.mlx_ptr, data->minimap.win_ptr);
		data->map_s.map[old_y][old_x] = '0';
		data->map_s.map[old_y + y][old_x + x ] = 'N';
	}
	return (EXIT_SUCCESS);	
}

void	rotate_player(t_data *data, int flag)
{
	if (flag == RIGHT)
		data->player.angle -= ft_convert_deg_rad(R_S);
	else if (flag == LEFT)
		data->player.angle += ft_convert_deg_rad(R_S);
	mlx_clear_window(data->minimap.mlx_ptr, data->minimap.win_ptr);
	ft_execution(data);
}

void	move_forward(t_data *data)
{
	float	x_change;
	float	y_change;

	x_change = data->player.x + cos(data->player.angle) * M_S;
	y_change = data->player.y - sin(data->player.angle) * M_S;
	if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] == '1')
		return ;
	mlx_clear_window(data->minimap.mlx_ptr, data->minimap.win_ptr);
	data->player.x = x_change;
	data->player.y = y_change;
	ft_execution(data);
}

void	move_backward(t_data *data)
{
	float	x_change;
	float	y_change;

	x_change = data->player.x - cos(data->player.angle) * M_S;
	y_change = data->player.y + sin(data->player.angle) * M_S;
	if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] == '1')
		return ;
	mlx_clear_window(data->minimap.mlx_ptr, data->minimap.win_ptr);
	data->player.x -= cos(data->player.angle) * M_S;
	data->player.y += sin(data->player.angle) * M_S;
	ft_execution(data);
}

// void	left_slide(t_data *data)
// {
// 	float	x_change;
// 	float	y_change;


// }

// this func find which key and move to the right direction
// |	0 : A	|	2 : D	|	1 : S	|	13 : W	|
int	key_detector(int keycode, t_data *data)
{
	(void)data;
	// if (keycode == 0)
	// 	left_slide(data);
	// if (keycode == 2)
	// 	update_minimap(data, 1, 0);
	if (keycode == 1)
		move_backward(data);
	if (keycode == 13)
		move_forward(data);
	if (keycode == 123)
		rotate_player(data, LEFT);
	if (keycode == 124)
		rotate_player(data, RIGHT);
	if (keycode == 53)
		exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}


// this func waitng for key pressed to call the right action
int	move_minimap(t_data *data)
{
	mlx_hook(data->minimap.win_ptr, 2, 1L<<2, key_detector, data);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	data.minimap.mlx_ptr = mlx_init();
	data.minimap.win_ptr = mlx_new_window(data.minimap.mlx_ptr, W_X, W_Y, "cube");
	data.minimap.img_ptr = mlx_new_image(data.minimap.mlx_ptr, W_X, W_Y);
	data.minimap.buff = mlx_get_data_addr(data.minimap.img_ptr, &data.minimap.bpp, &data.minimap.llength, &data.minimap.ein);		
	ft_get_starting_angle(&data);
	ft_execution(&data);
	move_minimap(&data);
	mlx_loop(data.minimap.mlx_ptr);
}
