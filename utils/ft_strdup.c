/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:23:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 20:31:11 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		len;
	int		idx;

	idx = 0;
	len = ft_strlen(str) + 1;
	ptr = (char *)malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (str[idx] != '\0')
	{
		ptr[idx] = str[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
