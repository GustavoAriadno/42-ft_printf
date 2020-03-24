/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:45:16 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/13 15:45:17 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_itoa_base(size_t value, int base, int al_case)
{
	char	*str;
	size_t	nb;
	size_t	i;

	nb = value;
	i = 1;
	while ((nb /= base) >= 1)
		i++;
	nb = value;
	if (!(str = (char *)malloc((i + 1) * sizeof(*str))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (nb % base < 10) ? nb % base + '0' : nb % base + al_case - 10;
		nb /= base;
	}
	return (str);
}
