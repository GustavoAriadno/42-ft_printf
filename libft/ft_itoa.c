/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:40:30 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/12 16:41:20 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	unsigned int	num;
	char			*str;
	int				minus;
	int				len;

	num = (nb < 0) ? -(unsigned int)nb : nb;
	minus = (nb < 0) ? 1 : 0;
	len = (minus == 1) ? 1 : 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	num = (nb < 0) ? -(unsigned int)nb : nb;
	if (!(str = malloc((len + 1) * sizeof(*str))))
		return (NULL);
	str[len] = '\0';
	while (--len >= minus)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	(minus) ? str[len] = '-' : 0;
	return (str);
}
