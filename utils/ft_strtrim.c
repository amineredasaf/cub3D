/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:29:04 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 13:32:51 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	ft_strlcpy(char	*dst,char *src,size_t dstsize)
{
	size_t	src_s;
	size_t	i;

	i = 0;
	src_s = ft_strlen(src);
	if (dstsize == 0)
		return (src_s);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_s);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		last;
	char	*ptr;

	ptr = NULL;
	if (s1 != NULL && set != NULL)
	{
		start = 0;
		last = ft_strlen(s1);
		while (s1[start] != '\0' && ft_isspace(s1[start]))
			start++;
		while ((ft_isspace(s1[last - 1])) && last > start)
			last--;
		ptr = (char *)malloc(sizeof(char) * (last - start + 1));
		if (ptr)
			ft_strlcpy(ptr, s1 + start, last - start + 1);
	}
	return (ptr);
}