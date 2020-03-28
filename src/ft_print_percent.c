/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:47:27 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/28 00:56:34 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_percent(t_info *info, t_flags *flags)
{
	char pading;

	pading = (flags->flag == ZERO) ? ZERO : SPACE;
	if (flags->flag == MINUS)
		info->len += ft_putchar('%');
	while (flags->width-- > 1)
		info->len += ft_putchar(pading);
	if (flags->flag != MINUS)
		info->len += ft_putchar('%');
}
