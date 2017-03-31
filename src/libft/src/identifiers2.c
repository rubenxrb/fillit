/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:48:04 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:48:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // is-blank, *is-emoji, <empty>, <empty> & <empty>

int		ft_isblank(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
	|| c == '\r'));
}

int		ft_ishex(int c)
{
	return ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || ft_isdigit(c));
}

int		ft_isemoji(int c)
{
	(void)c;
	return 0;
}
