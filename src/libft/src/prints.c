/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:16:18 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:16:19 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // putchar, putchar-fd, putstr, print-bits & <empty>
#include <unistd.h>

void	ft_putchar(int _c)
{
	wchar_t	c;

	(void)uctoutf8((char *)&c, _c);
	if (_c < 0x80)
		write(1, &c, 1);
	else if (_c < 0x800)
		write(1, &c, 2);
	else if (_c < 0x10000)
		write(1, &c, 3);
	else if (_c < 0x110000)
		write(1, &c, 4);
}

void	ft_putchar_fd(int _c, int fd)
{
	wchar_t	c;

	(void)uctoutf8((char *)&c, _c);
	if (_c < 0x80)
		write(fd, &c, 1);
	else if (_c < 0x800)
		write(fd, &c, 2);
	else if (_c < 0x10000)
		write(fd, &c, 3);
	else if (_c < 0x110000)
		write(fd, &c, 4);
}

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
			ft_putchar(*s++);
}

void	print_bits(unsigned char octet)
{
	int d;

	d = 128;
	while (d)
	{
		if (d <= octet)
		{
			write(1, "1", 1);
			octet = octet % d;
		}
		else
			write(1, "0", 1);
		d /= 2;
	}
}
