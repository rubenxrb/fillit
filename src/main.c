/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:32:12 by rromero           #+#    #+#             */
/*   Updated: 2016/10/26 14:32:13 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int arc, char *arv[])
{
	const char usage[] = "usage: ./fillit <pieces_file>";

	if (arc != 2)
		ft_putendl(usage);
	else
		ft_fillit(*++arv);
	return (0);
}
