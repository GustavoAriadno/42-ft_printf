/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:56:02 by gariadno          #+#    #+#             */
/*   Updated: 2020/04/01 16:29:49 by saopaulo42       ###   ########.fr       */
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
	len = ft_strlen(ptr);
	width = (flags->precision > len) ? flags->precision : len;
	(flags->precision >= 0 && flags->flag == ZERO) ? flags->flag = -1 : 0;
	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
	{
		ft_putstr(info, "0x");
		ft_addpads(flags->precision, len, info, ZERO);
		ft_putstr(info, ptr);
	}
	ft_addpads(flags->width - 2, width, info, pading);
	if (flags->flag != MINUS)
	{
		ft_putstr(info, "0x");
		ft_addpads(flags->precision, len, info, ZERO);
		ft_putstr(info, ptr);
	}
	free(ptr);
}
