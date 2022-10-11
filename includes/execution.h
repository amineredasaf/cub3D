/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:44:30 by rsaf              #+#    #+#             */
/*   Updated: 2022/08/27 03:46:28 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

float	ft_convert_deg_rad(float deg);
void	ft_execution(t_data *data);
void    ft_get_starting_angle(t_data *data);
void    line(t_data *data, int x0, int y0, int x1, int y1);
void	ft_get_starting_angle(t_data *data);
float	ft_line_len(t_data *data, float y);
int	    ft_count_lines(t_data *data);
void	ft_update_view_angle(t_data *data, int flag);
void	ft_draw_ray(t_data *data, t_ray *ray);
int		is_wall(t_data *data, int x, int y);
void	ft_first_hor(t_data *data, t_ray *ray, float angle);
void	ft_ver_check(t_data *data, t_ray *ray);
void	ft_first_ver(t_data *data, t_ray *ray, float angle);
void	ft_hor_check(t_data *data, t_ray *ray);
void	put_on_win(t_data *data, void *ptr, int x, int y);
void	*insert_img_buffer(t_data *data, int color, int x,int wall);

#endif
