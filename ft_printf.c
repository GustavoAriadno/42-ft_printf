/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:56:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/10 15:20:19 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_checktype(char c, t_info *info, t_flags *flags)
{
	if (c == 'd' || c == 'i')
		ft_print_di(info, flags);
	else if (c == 'u')
		ft_print_u(info, flags);
	else if (c == 'c')
		ft_print_c(info, flags);
/*	else if (c == 's')
		ft_print_s(info, flags);
	else if (c == 'p')
		ft_print_p(info, flags);
*/	else if (c == 'x')
		ft_print_x(info, flags, 'a');
	else if (c == 'X')
		ft_print_x(info, flags, 'A');
	else if (c == '%')
		ft_print_c(info, flags);
	info->i++;
}

void	ft_flagborn(t_flags *flags)
{
	flags->flag = -1;
	flags->width = -1;
	flags->dot = -1;
	flags->precision = -1;
	flags->specifier = -1;
}

void	ft_huntflags(t_info *info)
{
	t_flags	flags;

	info->i++;
	ft_flagborn(&flags);
	if (info->str[info->i] == '-' || info->str[info->i] == '0')
		flags.flag = (info->str[info->i++] == '-') ? MINUS : ZERO;
	if (info->str[info->i] == '*' || ft_isdigit(info->str[info->i]))
	{
		flags.width = (info->str[info->i] == '*') ?
			va_arg(info->args, int) : ft_miniatoi(info);
		(flags.width < 0) ? flags.flag = MINUS : 0;
		info->i++;
	}
	if (info->str[info->i] == DOT)
	{
		flags.dot = 1;
		info->i++;
		flags.precision = (info->str[info->i] == '*') ?
			va_arg(info->args, int) : ft_miniatoi(info);
		info->i++;
	}
	if (ft_strchr(SPECIFIER, info->str[info->i]))
		ft_checktype(info->str[info->i], info, &flags);
	else if (info->str[info->i] != '\0')
		info->i++;
}

int		ft_printf(const char *str, ...)
{
	t_info	info;
	int		len;

	info.str = str;
	info.len = 0;
	info.i = 0;
	va_start(info.args, str);
	while (info.str[info.i])
	{
		if (info.str[info.i] != '%')
		{
			info.len += ft_putchar(info.str[info.i]);
			info.i++;
		}
		else
			ft_huntflags(&info);
	}
	len = info.len;
	va_end(info.args);
	return (len);
}
