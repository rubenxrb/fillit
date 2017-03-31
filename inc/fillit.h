/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:00:29 by rromero           #+#    #+#             */
/*   Updated: 2016/10/26 15:00:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_board
{
	char			**tab;
	size_t			size;
}					t_board;

typedef struct		s_piece
{
	char			**piece;
	int				height;
	int				length;
	char			letter;
}					t_piece;

typedef struct		s_point
{
	size_t			x;
	size_t			y;
}					t_point;

void				ft_fillit(const char *file);
char				**ft_get_tetromino(char **buf, char *buf_str);
t_board				*ft_best_board(t_piece **piece_array, size_t count);
char				*ft_strxnew(const char *src, int c);
int					ft_valid_src(const char *src);
size_t				ft_piece_y(char **tetromino);
size_t				ft_piece_x(char **tetromino);
size_t				ft_init_size(t_piece **pieces);
size_t				ft_count_hash(char *str);

#endif
