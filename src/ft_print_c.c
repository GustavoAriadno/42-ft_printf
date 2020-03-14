/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 01:03:46 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/13 15:25:45 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_c(t_info *info, t_flags *flags)
{
	char pading;

	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
		info->len += ft_putchar(va_arg(info->args, int));
	while (flags->width-- > 1)
		info->len += ft_putchar(pading);
	if (flags->flag != MINUS)
		info->len += ft_putchar(va_arg(info->args, int));
}