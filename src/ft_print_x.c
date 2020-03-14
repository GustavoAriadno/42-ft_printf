/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:36:21 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/14 16:58:56 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_x(t_info *info, t_flags *flags, int alphacase)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa_base(va_arg(info->args, unsigned int), 16, alphacase);
	len = ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->dot == 1 && flags->flag == ZERO)
		flags->flag = -1;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		ft_putstr(info, num);
	}
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(flags->precision, len, info, '0');
		ft_putstr(info, num);
	}
}
