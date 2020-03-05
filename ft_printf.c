/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:56:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/05 16:39:59 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_checktpe(char c, t_info info, t_flags *flags)
{
	if (c == 'd' || c == 'i')
		ft_printdi(info, flags);
	else if (c == 'u')
		ft_printu(info, flags);
	else if (c == 'c')
		ft_printc(info, flags);
	else if (c == 's')
		ft_prints(info, flags);
	else if (c == 'p')
		ft_printp(info, flags);
	else if (c == 'x')
		ft_printx(info, flags, 0);
	else if (c == 'X')
		ft_printX(info, flags, 1);
}

t_flags	*ft_flagborn(t_flags *flags)
{
	if (!(flags = malloc(sizeof(*flags))))
		return (NULL);
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->asterisk = 0;
	flags->precision = 0;
	flags->specifier = 0;
	return (flags);
}

void	ft_huntflags(t_info *info)
{
	t_flags	*flags;

	info->i++;
	flags = ft_flagborn(flags);
	while (ft_strchr(FLAGS, info->str[info->i]))
	{
		(info->str[info->i] == '-') ? flags->minus = 1 : 0;
		(info->str[info->i++] == '0') ? flags->zero = 1 : 0;
	}
	flags->width = (info->str[info->i] == '*') ?
		va_arg(info->args, int) : ft_miniatoi(info);
	(flags->width < 0) ? flags->minus = 1 : 0;
	info->i++;
	while (ft_strchr(DOT, info->str[info->i]))
		(info->str[info->i++] == DOT) ? flags->dot = 1 : 0;
	flags->precision = (info->str[info->i] == '*') ?
		va_arg(info->args, int) : ft_miniatoi(info);
	info->i++;
	if (ft_strchr(SPECIFIER, info->str[info->i]))
		ft_checktype(info->args[info->i], flags);
	else
		info->i++;
}

int		ft_printf(const char *str, ...)
{
	t_info	*info;
	int		len;

	if (!(info = malloc(sizeof(*info))))
		return (0);
	info->str = str;
	info->len = 0;
	info->i = 0;
	va_start(info->args, str);
	while (info->str[info->i])
	{
		if (info->str[info->i] != '%')
		{
			info->len += ft_putchar(info->str[info->i]);
			info->i++;
		}
		else
			ft_huntflags(info);
	}
	len = info->len;
	va_end(info->args);
	free(info);
	return (len);
}
