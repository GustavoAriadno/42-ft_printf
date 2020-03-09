/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/09 16:31:52 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;

	num = ft_itoa_base(va_arg(info->args, unsigned int), 10, 'a');
	len = ft_strlen(num);
	width = (flags->precision > len) ? flags->precision : len;
	if (flags->dot == 1 && flags->flag == 1)
		flags->flag = -1;
	pading = (flags->flag == 1) ? '0' : ' ';
	if (flags->flag == 0)
	{
		while (flags->precision-- > len)
			info->len += ft_putchar('0');
		ft_putstr(info, num);
	}
	while (flags->width-- > width)
		info->len += ft_putchar(pading);
	if (flags->flag != 0)
	{
		while (flags->precision-- > len)
			info->len += ft_putchar('0');
		ft_putstr(info, num);
	}
}