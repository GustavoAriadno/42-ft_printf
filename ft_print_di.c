/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/12 15:07:50 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa(va_arg(info->args, int));
	len = ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->dot == 1 && flags->flag == ZERO)
		flags->flag = -1;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
	{
		ft_addpads(&(flags->precision), len, info, '0');
		ft_putstr(info, num);
	}
	ft_addpads(&(flags->width), width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_addpads(&(flags->precision), len, info, '0');
		ft_putstr(info, num);
	}
}
