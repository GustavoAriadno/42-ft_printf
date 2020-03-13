/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:03:47 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/13 10:37:15 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_addpads(int *duration, int len, t_info *info, int pad)
{
	while ((*duration)-- > len)
		info->len += ft_putchar(pad);
}

void	ft_putstr(t_info *info, char *s)
{
	int i;

	i = 0;
	while (s[i])
		info->len += ft_putchar(s[i++]);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_itoa_base(size_t value, int base, int al_case)
{
	char	*str;
	size_t	nb;
	size_t	i;
	int		sign;

	nb = (value < 0) ? -(size_t)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((nb /= base) >= 1)
		i++;
	nb = (value < 0) ? -(size_t)value : value;
	if (!(str = (char *)malloc((i + 1) * sizeof(*str))))
		return (NULL);
	str[i] = '\0';
	while (i-- + sign)
	{
		str[i] = (nb % base < 10) ? nb % base + '0' : nb % base + al_case - 10;
		nb /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
