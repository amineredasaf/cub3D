/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_killer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:16:47 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 16:49:36 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int kill_leaks(t_data *data, char *flag, char *mesg)
{
    int i;

    i = 0;
    while (flag[i])
    {
        if (flag[i] == 'F')
            ft_free_split(data->file_content);
        if (flag[i] == 'T')
            ft_free_split(data->textures);
        if (flag[i] == 'M')
            ft_free_split(data->map_s.map);
        i++;
    }
    exit(ft_print_error(mesg));
}