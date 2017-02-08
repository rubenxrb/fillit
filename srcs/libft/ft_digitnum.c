/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:59:03 by rromero           #+#    #+#             */
/*   Updated: 2016/10/14 12:59:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_digitnum(int n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}