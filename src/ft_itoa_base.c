/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:45:16 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/28 01:16:08 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_itoa_base(size_t nb, int base, int al_case)
{
	char	*str;
	size_t	tmp;
	size_t	i;

	tmp = nb;
	i = 1;
	while ((tmp /= base) >= 1)
		i++;
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
