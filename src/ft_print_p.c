/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:56:02 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/14 16:58:56 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_p(t_info *info, t_flags *flags)
{
	char	*ptr;
	char	pading;
	int		len;
	int		width;

	ptr = ft_itoa_base((size_t)va_arg(info->args, void *), 16, 'a');
	len = ft_strlen(ptr) + 2;
	width = (flags->precision > len) ? flags->precision : len;
	(flags->dot == 1 && flags->flag == ZERO) ? flags->flag = -1 : 0;
	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
	{
		ft_putstr(info, "0x");
		ft_addpads(flags->precision, len, info, '0');
		ft_putstr(info, ptr);
	}
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_putstr(info, "0x");
		ft_addpads(flags->precision, len, info, '0');
		ft_putstr(info, ptr);
	}
}
