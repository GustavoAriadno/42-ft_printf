/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:21:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/25 18:48:58 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_u(t_info *info, t_flags *flags)
{
	char			*num;
	char			pading;
	int				len;
	int				width;

	num = ft_itoa_base(va_arg(info->args, unsigned int), 10, 'a');
	len = (*num == '0' && flags->dot == 1 && flags->precision == 0) ? 0 : ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->dot == 1 && flags->flag == ZERO)
		flags->flag = -1;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		(*num == '0' && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
}
