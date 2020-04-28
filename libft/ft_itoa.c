/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:29:06 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/01 19:14:47 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_len(unsigned int x)
{
	int		len;

	len = 0;
	while (x > 9)
	{
		len++;
		x = x / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	char			*str;
	int				neg;

	len = 1;
	neg = 0;
	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		len++;
		neg++;
	}
	len = len + find_len(nb);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	neg == 1 ? str[0] = '-' : 0;
	str[len] = '\0';
	while (--len >= neg)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
