/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:29:55 by rromero           #+#    #+#             */
/*   Updated: 2016/11/18 11:29:56 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Reallocates ptr to the required new_size.
** if ptr does not exist, new ptr with new_size is returned.
*/

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	new = ft_memalloc(new_size);
	if (size > 0 && (ptr))
	{
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}
