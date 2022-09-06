/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/06 18:09:56 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	create_img_buffer(t_data *data)
{
	data->minimap.mlx_ptr = mlx_init();
	data->minimap.win_ptr = mlx_new_window(data->minimap.mlx_ptr, 1000, 1000, "cube");
	data->minimap.img_ptr = mlx_new_image(data->minimap.mlx_ptr, 20, 20);
	data->minimap.buff = (int *) mlx_get_data_addr(data->minimap.img_ptr, &data->minimap.bpp, &data->minimap.llength, &data->minimap.ein);
	int i = 0;
	int j = 0;
	while (i < 20) {
		while (j < 20) {
			data->minimap.buff[j + (i * (data->minimap.llength / 4))] = 0xFFFF00;
			j++;
		}
		i++;
		j = 0;
	}
	return (EXIT_SUCCESS);
}

int	ft_find_max(char **map)
{
	int	max;
	int	i;

	i = 1;
	max = ft_strlen(map[0]);
	while (map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen (map[i]);
		i++;
	}
	return (max);
}

// for testing some ideas
int	draw_minimap(t_data *data)
{
	int		len;
	char	**map;
	int		x;
	int		longest_line;

	map = data->map_s.map;
	data->map_s.longest_line = ft_find_max(map);
	int	y = 0;

	create_img_buffer(data);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(data->minimap.mlx_ptr, data->minimap.win_ptr, data->minimap.img_ptr, (500 + 70)  - (x * 20), y * 20);
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	draw_minimap(&data);
	mlx_loop(data.minimap.mlx_ptr);
}

