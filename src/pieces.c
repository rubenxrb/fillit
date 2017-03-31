/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:20:04 by rromero           #+#    #+#             */
/*   Updated: 2016/11/19 18:20:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

size_t	ft_piece_y(char **tetromino)
{
	size_t	height;
	int		i;

	i = 0;
	height = 1;
	while (tetromino[i])
	{
		if (ft_strchr(tetromino[i], '#'))
			height++;
		i++;
	}
	return (--height);
}

int		ft_vertical_hash(char **tetromino, int x)
{
	int		y;

	y = 0;
	while (tetromino[y])
	{
		if (tetromino[y][x] == '#')
			return (1);
		y++;
	}
	return (0);
}

size_t	ft_piece_x(char **tetromino)
{
	size_t	length;
	int		x;
	int		y;

	x = 0;
	y = 0;
	length = 0;
	while (tetromino[y][x])
		length += ft_vertical_hash(tetromino, x++);
	return (length);
}

t_piece	*ft_new_piece(char **tetromino, int count)
{
	t_piece		*current;

	current = (t_piece *)ft_memalloc(sizeof(t_piece));
	current->piece = tetromino;
	current->height = ft_piece_y(tetromino);
	current->length = ft_piece_x(tetromino);
	current->letter = 'A' + count;
	return (current);
}

void	ft_free_grid(char **grid, size_t size)
{
	size_t	index;

	index = 0;
	if (grid)
	{
		while (index < size)
		{
			ft_bzero(grid[index], size);
			free(grid[index++]);
		}
		*grid = 0;
	}
}
