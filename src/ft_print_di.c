/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/28 01:11:04 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	fucking_minus(t_info *info, char **num)
{
	if (num[0][0] == MINUS)
	{
		info->len += ft_putchar(MINUS);
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
	len = (*num == ZERO && flags->precision == 0) ? 0 : ft_strlen(num);
	(*num == MINUS && flags->precision > 1) ? flags->precision++ : 0;
	width = (flags->precision > len) ? flags->precision : len;
	(flags->flag == ZERO && flags->precision >= 0) ? flags->flag = -1 : 0;
	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
	{
		fucking_minus(info, &num);
		ft_addpads(flags->precision, len, info, ZERO);
		(*num == ZERO && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	(pading == ZERO) ? fucking_minus(info, &num) : 0;
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		fucking_minus(info, &num);
		ft_addpads(flags->precision, len, info, ZERO);
		(*num == ZERO && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	//	DO NOT FREE THE FREE
	//	free(num);
}
