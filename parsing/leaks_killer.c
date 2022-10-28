/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_killer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:16:47 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 16:26:45 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int kill_leaks(t_data *data, char *flag, char *mesg)
{
    int i;

    i = 0;
    // system("leaks cub3d");
    while (flag[i])
    {
            printf("done\n");
        if (flag[i] == 'F')
        {
            printf("F done\n");
            ft_free_split(data->file_content);
        }
        if (flag[i] == 'T')
        {
            printf("T done\n");
            ft_free_split(data->textures);
        }
        if (flag[i] == 'M')
        {
            printf("M done\n");
            ft_free_split(data->map_s.map);
        }
        i++;
    }
    printf("done\n");
    exit(ft_print_error(mesg));
}