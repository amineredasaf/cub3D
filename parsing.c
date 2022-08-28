/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:59:35 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/28 15:02:41 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

int	ft_check_cub(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	i--;
	if (name[i] == 'b' && name[i - 1] == 'u'
		&& name[i - 2] == 'c' && name[i - 3] == '.')
		return (1);
	return (0);
}