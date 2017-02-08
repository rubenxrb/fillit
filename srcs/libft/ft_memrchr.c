/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:30:38 by rromero           #+#    #+#             */
/*   Updated: 2016/10/27 23:30:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!n)
		return (0);
	p = (unsigned char *)s + n;
	while (n--)
	{
		if (*--p == (unsigned char)c)
			return (p);
	}
	return (0);
}
