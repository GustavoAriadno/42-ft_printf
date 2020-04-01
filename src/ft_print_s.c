/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:42:03 by gariadno          #+#    #+#             */
/*   Updated: 2020/04/01 19:26:48 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_put_s(t_info *info, char *s, int precision)
{
	int i;

	i = 0;
	while (i < precision && s[i])
		info->len += ft_putchar(s[i++]);
}

void		ft_print_s(t_info *info, t_flags *flags)
{
	char	*str;
	char	pading;
	int		len;
	int		width;

	str = va_arg(info->args, char *);
	(!str) ? str = STR_NULL : 0;
	len = ft_strlen(str);
	width = (flags->precision < len && flags->precision > -1) ?
		flags->precision : len;
	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
		ft_put_s(info, str, width);
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
		ft_put_s(info, str, width);
}
