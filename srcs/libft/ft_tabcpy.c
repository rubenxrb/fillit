/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:17:40 by rromero           #+#    #+#             */
/*   Updated: 2016/11/19 17:17:42 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabcpy(void **src, void **dst, size_t size)
{
	unsigned char	**s;
	unsigned char	**d;
	size_t			index;

	s = (unsigned char **)src;
	d = (unsigned char **)dst;
	index = 0;
	while (index < size)
	{
		*d[index] = (unsigned char *)ft_memcpy(&d[index], &s[index], size);
		index++;
	}
}
