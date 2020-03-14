/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/14 20:15:35 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

static void	fucking_minus(t_info *info, char **num, int *len)
{
	if (num[0][0] == '-')
	{
		info->len += ft_putchar('-');
		(*num)++;
		(*len)--;
	}
}

void		ft_print_di(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa(va_arg(info->args, int));
	//(*num == '-') ? flags->width-- : 0;
	len = (*num == '0' && flags->precision <= 0) ? 0 : ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->dot == 1 && flags->flag == ZERO)
		flags->flag = -1;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
	{
		fucking_minus(info, &num, &len);
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	(pading == '0') ? fucking_minus(info, &num, &len) : 0;
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
}
