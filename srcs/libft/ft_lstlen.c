/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:24:45 by rromero           #+#    #+#             */
/*   Updated: 2016/10/22 20:24:46 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *head)
{
	size_t	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
