/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:38:05 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/01 19:26:16 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int x;

	if (n < 0)
	{
		write(fd, "-", 1);
		x = n * -1;
	}
	else
		x = n;
	if (x < 10 && x >= 0)
		ft_putchar_fd(x % 10 + 48, fd);
	else if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
}
