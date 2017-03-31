/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:05:42 by rromero           #+#    #+#             */
/*   Updated: 2017/03/23 09:09:45 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_snode				*snode_new(void const *data, size_t d_size)
{
	t_snode	*new;

	new = ft_memalloc(sizeof(t_snode));
	if (!new)
		return (0);
	if (!data)
	{
		new->data = 0;
		new->data = 0;
	}
	else if (d_size)
	{
		new->data = ft_memalloc(d_size);
		if (!new->data)
		{
			ft_memdel((void **)new);
			return (0);
		}
		new->data = ft_memcpy(new->data, data, d_size);
		new->d_size = d_size;
	}
	new->prev = 0;
	return (new);
}

t_snode				*stack_push(t_snode *top, t_snode *new)
{
	if (!top || !new)
		return (0);
	new->prev = top;
	return (new);
}

t_snode				*stack_pop(t_snode *top)
{
	t_snode	*prev;

	if (!top)
		return (0);
	prev = top->prev;
	top->prev = 0;
	return (prev);
}

t_snode				*stack_lookup(t_snode *top, t_snode *node)
{
	if (!top || !node)
		return (0);
	while ((top->prev) && top != node)
		top = top->prev;
	return (top == node ? node : 0);
}

int				snode_del(t_snode *node)
{
	if (!node)
		return (0);
	ft_memdel(&node->data);
	ft_memdel((void **)node);
	return (1);
}
