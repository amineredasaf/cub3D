/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/18 18:29:25 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		dst = data->mlx_s.buff + (y * data->mlx_s.llength + x * (data->mlx_s.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	t_mlx map;

	map = data->mlx_s;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x, y);
}

void	rotate_player(t_data *data, int flag)
{
	if (flag == RIGHT)
		data->player.angle -= ft_convert_deg_rad(R_S);
	else if (flag == LEFT)
		data->player.angle += ft_convert_deg_rad(R_S);
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
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
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
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
	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
	data->player.x -= cos(data->player.angle) * M_S;
	data->player.y += sin(data->player.angle) * M_S;
	ft_execution(data);
}

// void	left_slide(t_data *data)
// {
// 	float	x_change;
// 	float	y_change;


// }

// void	left_slide(t_data *data)
// {
// 	float	x_change;
// 	float	y_change;

// 	x_change = data->player.x + cos(data->player.angle) * 60;
// 	y_change = data->player.y - sin(data->player.angle) * 60;
// 	if (data->map_s.map[(int)floor(y_change / 64)][(int)floor(x_change / 64)] == '1')
// 		return ;
// 	mlx_clear_window(data->mlx_s.mlx_ptr, data->mlx_s.win_ptr);
// 	data->player.x = x_change;
// 	data->player.y = y_change;
// 	ft_execution(data);	
// }

// this func find which key and move to the right direction
// |	0 : A	|	2 : D	|	1 : S	|	13 : W	|
int	key_detector(int keycode, t_data *data)
{
	(void)data;
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
int	key_pressed(t_data *data)
{
	mlx_hook(data->mlx_s.win_ptr, 2, 1L<<2, key_detector, data);
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
	data.mlx_s.mlx_ptr = mlx_init();
	data.mlx_s.win_ptr = mlx_new_window(data.mlx_s.mlx_ptr, W_X, W_Y, "cube");
	data.mlx_s.img_ptr = mlx_new_image(data.mlx_s.mlx_ptr, W_X, W_Y);
	data.mlx_s.buff = mlx_get_data_addr(data.mlx_s.img_ptr, &data.mlx_s.bpp, &data.mlx_s.llength, &data.mlx_s.ein);		
	ft_get_starting_angle(&data);
	ft_execution(&data);
	key_pressed(&data);
	mlx_loop(data.mlx_s.mlx_ptr);
}
