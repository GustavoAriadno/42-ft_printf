/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:36:21 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/29 18:33:09 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_x(t_info *info, t_flags *flags, char alpha_case)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa_base(va_arg(info->args, unsigned int), 16, alpha_case);
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
