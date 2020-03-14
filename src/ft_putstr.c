/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:44:30 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/13 15:44:34 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstr(t_info *info, char *s)
{
	int i;

	i = 0;
	while (s[i])
		info->len += ft_putchar(s[i++]);
}
