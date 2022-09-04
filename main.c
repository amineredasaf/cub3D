/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/03 18:39:41 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	call_me(t_data *data, int len)
{
	data->minimap.mlx_ptr = mlx_init();
	data->minimap.win_ptr = mlx_new_window(data->minimap.mlx_ptr, 1000, 1000, "cube");
	data->minimap.img_ptr = mlx_new_image(data->minimap.mlx_ptr, 20, 20);
	data->minimap.buff = (int *) mlx_get_data_addr(data->minimap.img_ptr, &data->minimap.bits_per_pixel, &data->minimap.line_length, &data->minimap.endian);

	int x = 0;
	int y = 0;
	
	while (y < 20) {
		while (x < 20) {
			data->minimap.buff[x + (y * (data->minimap.line_length / 4))] = 0x00FF0000;
			++x;
		}
		++y;
		x = 0;
	}
	// x, y = buffer[x + y * sizeLine];
	mlx_put_image_to_window(data->minimap.mlx_ptr, data->minimap.win_ptr, data->minimap.img_ptr, 1000/2 - (20/2), 0);
	return (EXIT_SUCCESS);
}

// for testing some ideas
int	hard_code(t_data *data)
{
	int		len;
	char	**line;
	int		x;

	len = ft_strlen(line[0]);
	line = data->map_s.map;
	x = 0;
	while (line[0][x])
	{
		if (line[0][x] == ' ' || line[0][x] == 1)
		{
			HERE
			call_me(data, len);
		}
		x++;
	}
	mlx_loop(data->minimap.mlx_ptr);
	
}





int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	hard_code(&data);

}

