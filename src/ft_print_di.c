/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:29:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/04/01 21:27:27 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_putdi(int precision, int len, t_info *info, char *num)
{
	int negative;

	negative = (*num == MINUS) ? 1 : 0;
	if (*num == MINUS)
		info->len += ft_putchar(MINUS);
	ft_addpads(precision, len, info, ZERO);
	(*num == ZERO && precision == 0) ? 0 : ft_putstr(info, num + negative);
}

void		ft_print_di(t_info *info, t_flags *flags)
{
	char	*num;
	char	pading;
	int		len;
	int		width;
	int		isminus;

	num = ft_itoa(va_arg(info->args, int));
	isminus = (*num == MINUS) ? 1 : 0;
	len = (*num == ZERO && flags->precision == 0) ? 0 : ft_strlen(num);
	(*num == MINUS && flags->precision > 1) ? flags->precision++ : 0;
	width = (flags->precision > len) ? flags->precision : len;
	(flags->flag == ZERO && flags->precision >= 0) ? flags->flag = -1 : 0;
	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
		ft_putdi(flags->precision, len, info, num);
	if (pading == ZERO && isminus)
		info->len += ft_putchar(MINUS);
	else
		isminus = 0;
	ft_addpads(flags->width, width, info, pading);
	if (flags->flag != MINUS)
		ft_putdi(flags->precision, len, info, num + isminus);
	free(num);
}
