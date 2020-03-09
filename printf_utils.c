/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:03:47 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/09 16:32:17 by gariadno         ###   ########.fr       */
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

void	ft_putstr(t_info *info, char *s)
{
	int i;

	i = 0;
	while (s[i])
		info->len += ft_putchar(s[i++]);
}

int		ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_miniatoi(t_info *info)
{
	int	num;

	num = 0;
	while (ft_isdigit(info->str[info->i]))
		num = (num * 10) + info->str[info->i++] - '0';
	info->i--;
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
	return (0);
}

char	*ft_itoa_base(int value, int base, int c)
{
	char	*str;
	long	nb;
	int		sign;
	int		i;

	nb = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((nb /= base) >= 1)
		i++;
	nb = (value < 0) ? -(long)value : value;
	if (!(str = (char *)malloc((i + 1) * sizeof(*str))))
		return (NULL);
	str[i] = '\0';
	while (i-- + sign)
	{
		str[i] = (nb % base < 10) ? nb % base + '0' : nb % base + c - 10;
		nb /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
