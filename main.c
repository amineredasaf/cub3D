/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/07 01:42:13 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// this func insert img to a buffer pixel by pixel to create a img
void	*insert_img_buffer(t_data *data, int color)
{
	int		i;
	int		j;
	void	*ptr;
	t_mlx	*map;

	j = 0;
	i = 0;
	map = &data->minimap;
	ptr = mlx_new_image(map->mlx_ptr, IMG_S, IMG_S);
	map->buff = (int *) mlx_get_data_addr(ptr, &map->bpp, &map->llength, &map->ein);
	while (i < IMG_S)
	{
		while (j < IMG_S) {
			map->buff[j + (i * (map->llength / 4))] = color;
			j++;
		}
		i++;
		j = 0;
	}
	return (ptr);
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	int	y_side;
	int	x_side;
	t_mlx map;

	y_side = y * IMG_S;
	x_side = (x * IMG_S);
	map = data->minimap;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x_side, y_side);
}

// for testing some ideas
int	draw_minimap(t_data *data)
{
	int		y;
	int		x;
	int		len;
	char	**map;

	y = 0;
	map = data->map_s.map;
	data->minimap.wall_ptr = insert_img_buffer(data, 0xFFFFFF);
	data->minimap.play_ptr = insert_img_buffer(data, 0x12FF00);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || ft_isspace(map[y][x]))
				put_on_win(data, data->minimap.wall_ptr, x, y);
			else if (map[y][x] == 'N')
			{
				data->minimap.x = x;
				data->minimap.y = y;
				put_on_win(data, data->minimap.play_ptr, x, y);
			}
			x++;
		}
		y++;
	}
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
		draw_minimap(data);
	}
	return (EXIT_SUCCESS);	
}

// this func find which key and move to the right direction
// |	0 : A	|	2 : D	|	1 : S	|	13 : W	|
int	key_detector(int keycode, t_data *data)
{

	if (keycode == 0)
		update_minimap(data, -1, 0);
	if (keycode == 2)
		update_minimap(data, 1, 0);
	if (keycode == 1)
		update_minimap(data, 0, 1);
	if (keycode == 13)
		update_minimap(data, 0, -1);
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
	draw_minimap(&data);
	move_minimap(&data);
	mlx_loop(data.minimap.mlx_ptr);
}

