/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:51:00 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/26 20:29:47 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	while (len > 0)
	{
		ptr[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}

void	ft_bzero(void	*s, size_t	n)
{
	s = ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*ptr;
	size_t	sizee;

	sizee = count * size;
	ptr = (void *)malloc(sizee);
	if (ptr != NULL)
		ft_bzero(ptr, sizee);
	else
		return (NULL);
	return (ptr);
}
