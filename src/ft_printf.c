/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:56:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/31 20:13:36 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_miniatoi(t_info *info)
{
	int	num;

	num = 0;
	while (ft_isdigit(info->str[info->i]))
		num = (num * 10) + (info->str[info->i++] - '0');
	info->i--;
	return (num);
}

static void	ft_checktype(char specifier, t_info *info, t_flags *flags)
{
	if (!specifier)
		return ;
	else if (specifier == DECIMAL || specifier == INTEGER)
		ft_print_di(info, flags);
	else if (specifier == UNSIGNED)
		ft_print_u(info, flags);
	else if (specifier == CHAR)
		ft_print_c(info, flags);
	else if (specifier == STRING)
		ft_print_s(info, flags);
	else if (specifier == POINTER)
		ft_print_p(info, flags);
	else if (specifier == LOW_HEXA)
		ft_print_x(info, flags, LOWER_CASE);
	else if (specifier == UP_HEXA)
		ft_print_x(info, flags, UPPER_CASE);
	else if (specifier == PERCENT)
		ft_print_percent(info, flags);
	info->i++;
}

static void	ft_huntflags(t_info *info, t_flags flags)
{
	while (info->str[info->i] == MINUS || info->str[info->i] == ZERO)
		if (info->str[info->i++] == ZERO && flags.flag != MINUS)
			flags.flag = ZERO;
		else
			flags.flag = MINUS;
	if (info->str[info->i] == ASTERISK || ft_isdigit(info->str[info->i]))
	{
		flags.width = (info->str[info->i] == ASTERISK) ?
			va_arg(info->args, int) : ft_miniatoi(info);
		(flags.width < 0) ? flags.flag = MINUS : 0;
		(flags.width < 0) ? flags.width = flags.width * -1 : 0;
		info->i++;
	}
	if (info->str[info->i] == DOT)
	{
		info->i++;
		flags.precision = (info->str[info->i] == ASTERISK) ?
			va_arg(info->args, int) : ft_miniatoi(info);
		info->i++;
	}
	if (ft_strchr(SPECIFIER, info->str[info->i]))
		ft_checktype(info->str[info->i], info, &flags);
	else
		info->i++;
}

static void	ft_flagborn(t_flags *flags)
{
	flags->flag = -1;
	flags->width = -1;
	flags->precision = -1;
}

int			ft_printf(const char *str, ...)
{
	t_info	info;
	t_flags	flags;

	info.str = str;
	info.len = 0;
	info.i = 0;
	va_start(info.args, str);
	while (info.str[info.i])
	{
		if (info.str[info.i] != '%')
			info.len += ft_putchar(info.str[info.i++]);
		else
		{
			info.i++;
			ft_flagborn(&flags);
			ft_huntflags(&info, flags);
		}
	}
	va_end(info.args);
	return (info.len);
}
