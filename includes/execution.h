/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:44:30 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 12:32:07 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

// **       RAY EXECUTION       ** //
//---------------------------------//
float	ft_convert_deg_rad(float deg);
int		ft_execution(t_data *data);
void	ft_get_starting_angle(t_data *data);
void	ft_get_starting_angle(t_data *data);
float	ft_line_len(t_data *data, float y);
int		ft_count_lines(t_data *data);
void	ft_update_view_angle(t_data *data, int flag);
void	ft_draw_ray(t_data *data, t_ray *ray);
int		is_wall(t_data *data, int x, int y);
void	ft_first_hor(t_data *data, t_ray *ray, float angle);
void	ft_ver_check(t_data *data, t_ray *ray);
void	ft_first_ver(t_data *data, t_ray *ray, float angle);
void	ft_hor_check(t_data *data, t_ray *ray);

// **       MLX EXECUTION       ** //
//---------------------------------//

// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color);
// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y);
void	prepare_textures(t_data *data);

int		color_convert(t_data *data, char *buff, int lenght);

// **       Moves EXECUTION     ** //

int		key_pressed(t_data *data);

void	rotate_player(t_data *data, int flag);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
int		destroy_win(int keycode, t_data *data);
int		ft_can_move(t_data *data, float x, float y);
#endif