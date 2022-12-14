/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:35:16 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 22:06:31 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		ft_check_cub(char *name);
int		ft_parsing(t_data *data);
int		ft_parse_textures(t_data *data);
int		ft_parse_map(t_data *data);
int		kill_leaks(t_data *data, char *flag, char *mesg);
int		ft_isvalid(char c);
void	free_allocation(t_data *data);
void	ft_get_colors(t_data *data);
void	ft_fill_lines(t_data *data, int i, int j);
void	ft_read_file(t_data *data);
void	ft_split_textures(t_data *data);
void	ft_parse_player(t_data *data);
void	freeit(t_data *data, char *line);
void	free_allocation(t_data *data);
//         parsing utils       */
int		ft_issides(char *line, char a, char b, int flag);
int		ft_is_map(char *line);
int		ft_check_after_id(t_data *data);
void	ft_update_txt(t_data *data);
void	*ft_calloc(size_t	count, size_t	size);
void	ft_free_split(char **str);

#endif // PARSING_H
