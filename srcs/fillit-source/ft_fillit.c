/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 21:10:35 by rromero           #+#    #+#             */
/*   Updated: 2016/10/26 21:10:36 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

size_t	g_tetris = 0;

t_piece	**ft_del_pieces(t_piece **list, int n)
{
	t_piece		*current;
	int			i;
	int			e;

	e = 0;
	while (n--)
	{
		current = list[e];
		i = 0;
		while (i < current->height)
		{
			ft_bzero(current->piece[i], current->length);
			free(current->piece[i++]);
		}
		free(list[e++]);
	}
	return (0);
}

t_piece	**ft_get_pieces(int fd)
{
	char	*buf;
	t_piece	**list;
	char	**tetromino;
	int		nread;
	int		flag;

	tetromino = 0;
	list = 0;
	flag = 0;
	buf = ft_strnew(21);
	while ((nread = read(fd, buf, 21) > 0) && g_tetris < 26)
	{
		if ((tetromino) && ft_strlen(buf) < 21)
			flag++;
		if (!(tetromino = ft_get_tetromino(ft_strsplit(buf, '\n'), buf)))
			return (ft_del_pieces(list, g_tetris));
		list = (t_piece **)ft_realloc(list, (sizeof(t_piece *) * (g_tetris)),
				(sizeof(t_piece *) * (g_tetris + 1)));
		list[g_tetris] = ft_new_piece(tetromino, g_tetris);
		g_tetris++;
		ft_bzero(buf, 21);
	}
	free(buf);
	return ((flag) ? (list) : (0));
}

t_board	*ft_get_board(int fd)
{
	t_board	*f_board;
	t_piece	**pieces;

	f_board = 0;
	pieces = 0;
	if (!(pieces = ft_get_pieces(fd)))
		return (0);
	f_board = ft_best_board(pieces, g_tetris);
	return (f_board);
}

void	ft_print_board(t_board *f_board)
{
	size_t	i;

	i = 0;
	if (f_board->tab)
		while (i < f_board->size)
			ft_putendl(f_board->tab[i++]);
}

void	ft_fillit(const char *file)
{
	int			fd;
	t_board		*board;
	const char	*r_error = "error";

	board = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_putendl(r_error);
	else
	{
		if ((board = ft_get_board(fd)))
		{
			ft_print_board(board);
			ft_free_grid(board->tab, board->size);
			free(board);
		}
		else
			ft_putendl(r_error);
		close(fd);
	}
}
