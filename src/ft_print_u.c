/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:21:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/28 01:07:16 by saopaulo42       ###   ########.fr       */
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
	len = (*num == ZERO && flags->precision == 0) ? 0 : ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->flag == ZERO && flags->precision >= 0)
		flags->flag = -1;
	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
	{
		ft_addpads(flags->precision, len, info, ZERO);
		(*num == ZERO && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(flags->precision, len, info, ZERO);
		(*num == ZERO && flags->precision == 0) ? 0 : ft_putstr(info, num);
	}
	free(num);
}
