/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:42:20 by rromero           #+#    #+#             */
/*   Updated: 2016/10/27 14:42:21 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_move_piece(t_board *board, t_piece *piece, t_point origin, char curr)
{
	t_point	tmp;

	tmp.x = 0;
	while (tmp.x < (size_t)piece->length)
	{
		tmp.y = 0;
		while (tmp.y < (size_t)piece->height)
		{
			if (piece->piece[tmp.y][tmp.x] == '#')
				board->tab[origin.y + tmp.y][origin.x + tmp.x] = curr;
			tmp.y += 1;
		}
		tmp.x += 1;
	}
}

int		ft_put_piece(t_board *board, t_piece *piece, t_point origin)
{
	t_point	tmp;

	tmp.x = 0;
	while (tmp.x < (size_t)piece->length)
	{
		tmp.y = 0;
		while (tmp.y < (size_t)piece->height)
		{
			if (piece->piece[tmp.y][tmp.x] == '#' &&
				board->tab[origin.y + tmp.y][origin.x + tmp.x] != '.')
				return (0);
			tmp.y += 1;
		}
		tmp.x += 1;
	}
	ft_move_piece(board, piece, origin, piece->letter);
	return (1);
}

int		ft_fill_board(t_board *tmp, t_piece **pieces, size_t count)
{
	t_point	origin;
	t_piece	*current;

	if (!(current = *pieces))
		return (1);
	origin.y = 0;
	while (origin.y < tmp->size - current->height + 1)
	{
		origin.x = 0;
		while (origin.x < tmp->size - current->length + 1)
		{
			if (ft_put_piece(tmp, current, origin))
			{
				if (ft_fill_board(tmp, ++pieces, count))
					return (1);
				else
					ft_move_piece(tmp, current, origin, '.');
				--pieces;
			}
			origin.x += 1;
		}
		origin.y += 1;
	}
	return (0);
}

size_t	ft_init_size(t_piece **pieces)
{
	t_piece *current;
	size_t	hash;
	size_t	x;
	size_t	size;
	size_t	index;

	hash = 0;
	while ((current = *pieces++))
	{
		index = 0;
		while (current->piece[index])
			hash += ft_count_hash(current->piece[index++]);
	}
	size = 1;
	x = 1;
	while (size < hash)
	{
		if (size == hash)
			return (size);
		x++;
		size = (x * x);
	}
	return (x);
}

size_t	ft_count_hash(char *str)
{
	size_t count;

	count = 0;
	while (*str)
		if (*str++ == '#')
			count++;
	return (count);
}
