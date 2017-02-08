/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 20:23:57 by rromero           #+#    #+#             */
/*   Updated: 2016/11/20 20:23:58 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

const char	*g_patterns[] =
{	"##..##",
	"####",
	"#...#...#...#",
	"##.##",
	"#...##...#",
	"##...##",
	"#..##..#",
	"###.#",
	"#...#...##",
	"#.###",
	"##...#...#",
	"###...#",
	"##..#...#",
	"#...###",
	"#...#..##",
	"###..#",
	"#...##..#",
	"#..###",
	"#..##...#"};

int			ft_valid_buf(char *buf_str)
{
	char	*tetromino;
	char	*tmp;
	char	*first;
	char	*last;
	size_t	index;

	first = ft_strchr(buf_str, '#');
	last = ft_strrchr(buf_str, '#');
	if ((!last || !first) || ft_strlen(buf_str) < 19)
		return (0);
	tetromino = ft_strnew((size_t)(last - first) + 1);
	ft_strncpy(tetromino, first, ((size_t)(last - first) + 1));
	tmp = ft_strxnew(tetromino, '\n');
	if (!(ft_valid_src(tmp)))
		return (0);
	index = 0;
	while (index < 19)
		if (ft_strcmp(g_patterns[index++], tmp) == 0)
			return (1);
	free(tetromino);
	free(tmp);
	return (0);
}

int			ft_valid_tab(char **buf)
{
	int		hash;
	int		i;
	int		e;

	hash = 4;
	i = 0;
	while (buf[i])
	{
		if (ft_strlen(buf[i]) < 4)
			return (0);
		e = 0;
		while (buf[i][e])
		{
			if (buf[i][e] != '#' && buf[i][e] != '.')
				return (0);
			if (buf[i][e] == '#')
				hash--;
			e++;
		}
		i++;
	}
	return ((hash) ? 0 : 1);
}

int			ft_get_col(char **buf)
{
	char	*l_hash;
	int		tmp;
	int		col;
	int		x;

	x = 0;
	col = 4;
	while (buf[x])
	{
		if ((l_hash = ft_strchr(buf[x], '#')))
			tmp = (l_hash - buf[x]);
		if (tmp < col)
			col = tmp;
		x++;
	}
	return (col);
}

char		**ft_trim_piece(char **buf, size_t height, size_t length)
{
	char	**tetromino;
	char	*tmp;
	size_t	x;
	size_t	y;
	int		col;

	x = 0;
	y = 0;
	tetromino = (char **)ft_memalloc(sizeof(char *) * (height + 1));
	tetromino[height] = 0;
	tmp = ft_strnew(length);
	col = ft_get_col(buf);
	while (buf[x] && y < height)
	{
		if (ft_strchr(buf[x], '#'))
			tetromino[y++] = ft_strdup(ft_strncpy(tmp, &buf[x][col], length));
		x++;
	}
	free(tmp);
	return (tetromino);
}

char		**ft_get_tetromino(char **buf, char *buf_str)
{
	char	**tetromino;
	size_t	length;
	size_t	height;

	if (ft_valid_buf(buf_str) == 0)
		return (0);
	if (ft_valid_tab(buf) == 0)
		return (0);
	length = ft_piece_x(buf);
	height = ft_piece_y(buf);
	tetromino = ft_trim_piece(buf, height, length);
	return (tetromino);
}
