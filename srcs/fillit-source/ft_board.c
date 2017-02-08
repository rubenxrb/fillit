/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:20:10 by rromero           #+#    #+#             */
/*   Updated: 2016/11/19 18:20:12 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	**ft_allocate_tab(size_t size)
{
	size_t	index;
	char	**tab;

	tab = 0;
	index = 0;
	tab = (char **)ft_memalloc(sizeof(*tab) * size);
	while (index < size)
	{
		tab[index] = ft_strnew(size);
		ft_memset(tab[index++], '.', size);
	}
	return (tab);
}

t_board	*ft_new_board(size_t size)
{
	t_board	*new;

	new = (t_board *)ft_memalloc(sizeof(t_board));
	new->size = size;
	new->tab = ft_allocate_tab(size);
	return (new);
}

t_board	*ft_best_board(t_piece **piece_array, size_t count)
{
	t_board		*tmp;
	int			size;

	size = ft_init_size(piece_array);
	tmp = ft_new_board(size);
	while (!ft_fill_board(tmp, piece_array, count))
	{
		tmp->size += 1;
		ft_free_grid(tmp->tab, tmp->size - 1);
		tmp->tab = ft_allocate_tab(tmp->size);
	}
	return (tmp);
}

char	*ft_strxnew(const char *src, int c)
{
	char		*p;
	char		*s;
	size_t		i;
	size_t		e;

	i = 0;
	e = 0;
	p = (char *)src;
	while (p[e])
		if (p[e++] != c)
			i++;
	s = ft_strnew(i);
	i = 0;
	e = 0;
	while (p[i])
	{
		if (p[i] == c)
			i++;
		else
			s[e++] = p[i++];
	}
	return (s);
}

int		ft_valid_src(const char *src)
{
	while (*src)
	{
		if (*src != '#' && *src != '.')
			return (0);
		src++;
	}
	return (1);
}
