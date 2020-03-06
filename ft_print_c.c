/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 01:03:46 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/06 12:09:32 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_info *info, t_flags *flags)
{
	char c;

	c = (flags->flag == 1) ? '0' : ' ';
	if (flags->flag == 0)
		info->len += ft_putchar(va_arg(info->args, int));
	while (flags->width-- > 1)
		info->len += ft_putchar(c);
	if (flags->flag != 0)
		info->len += ft_putchar(va_arg(info->args, int));
}
