/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/26 13:49:43 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	fucking_minus(t_info *info, char **num)
{
	if (num[0][0] == '-')
	{
		info->len += ft_putchar('-');
		(*num)++;
	}
}

void		ft_print_di(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa(va_arg(info->args, int));
	len = (*num == '0' && flags->precision == 0) ? 0 : ft_strlen(num);
	(*num == '-' && flags->precision > 1) ? flags->precision++ : 0;
	width = (flags->precision > len) ? flags->precision : len;
	(flags->flag == ZERO  && flags->precision >= 0) ? flags->flag = -1 : 0;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)  
	{
		fucking_minus(info, &num);
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	(pading == '0') ? fucking_minus(info, &num): 0;
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		fucking_minus(info, &num);
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
}
