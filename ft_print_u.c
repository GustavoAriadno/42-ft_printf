/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:21:59 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/07 18:44:32 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(t_info *info, t_flags *flags)
{
	char	pading;
	int		len;

	if (flags->dot == 1 && flags->flag == 1)
		flags->flag = -1;
	pading = (flags->flag == 1) ? '0' : ' ';
	if (flags->flag == 0)
	{
		while (flags->width)
	}
}
