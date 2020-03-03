/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:56:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/03 16:54:53 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		ft_ifs(int c, va_list args, t_flags flags)
{
	if (c == 'd' || c == 'i')
		return ();
	else if (c == 'u')
		return ();
	else if (c == 'c')
		return ();
	else if (c == 's')
		return ();
	else if (c == 'p')
		return ();
	else if (c == 'x')
		return ();
	else if (c == 'X')
		return ();
}
*/

t_flags		*ft_flagborn(t_flags *flags)
{
	if (!(flags = malloc(sizeof(*flags))))
		return (NULL);
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->asterisk = 0;
	flags->specifier = 0;
	return (flags);
}

void		ft_huntflags(t_info *info)
{
	t_flags	*flags;

	info->i++;
	flags = ft_flagborn(flags);
	while (ft_strchr(FLAGS, info->str[info->i]))
	{
		(info->str[info->i] == '-') ? flags->minus = 1 : 0;
		(info->str[info->i++] == '0') ? flags->zero = 1 : 0;
	}
	flags->width = ft_atoi(info->str[info->i]);
	return ;
}

int		ft_printf(const char *str, ...)
{
	t_info	*info;

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
	va_end(info->args);
	return (info->len);
}
