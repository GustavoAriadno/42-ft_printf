/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:47:27 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/10 14:18:50 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_info *info, t_flags *flags)
{
	char pading;

	pading = (flags->flag == ZERO) ? '0' : ' ';
	if (flags->flag == MINUS)
		info->len += ft_putchar('%');
	while (flags->width-- > 1)
		info->len += ft_putchar(pading);
	if (flags->flag != MINUS)
		info->len += ft_putchar('%');
}
