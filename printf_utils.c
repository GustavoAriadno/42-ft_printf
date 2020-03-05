/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:03:47 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/04 16:26:25 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_miniatoi(t_info *info)
{
	int	num;

	num = 0;
	while (ft_isdigit(info->str[info->i]))
	{
		num = (num * 10) + info->str[info->i++] - '0';
	}
	return (num);
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
	if (c == 0)
		return (&str[i]);
	return (0);
}