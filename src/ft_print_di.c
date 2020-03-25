/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/25 18:49:08 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

static void	fucking_minus(t_info *info, char **num)
{
	if (num[0][0] == '-')
	{
		info->len += ft_putchar('-');
		(*num)++;
		//(*len)--;
	}
}

void		ft_print_di(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa(va_arg(info->args, int));
	len = (*num == '0' && flags->dot == 1 && flags->precision == 0) ? 0 : ft_strlen(num);
	(*num == '-' && flags->precision != -1) ? flags->precision++ : 0;
	width = (flags->precision > len) ? flags->precision : len;
	(flags->dot == 1 && flags->flag == ZERO  && flags->precision >= 0) ? flags->flag = -2 : 0;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)  
	{
		fucking_minus(info, &num);
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	//(pading == '0' || flags->dot == 1) ? fucking_minus(info, &num, &len) : 0;
	//((pading == '0' || flags->dot == 1) && flags->flag != -2) ? fucking_minus(info, &num, &len) : 0;
	//((pading == '0' || width > len) && *num == '-') ? fucking_minus(info, &num, &len) : 0;
	//(pading == '0' || flags->width-- < width || flags->precision-- > width) ? fucking_minus(info, &num, &len): 0;
	(pading == '0' || flags->width <= width) ? fucking_minus(info, &num): 0;
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
}
