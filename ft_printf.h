/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:34:00 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/03 11:17:11 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define SPECIFIER "dicspuxX%"
# define FLAGS "- 0"



typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	asterisk;
	int specifier;
}				t_flags;

typedef struct	s_info
{
	const char	*str;
	va_list		args;
	int			len;
	int			i;
}				t_info;

int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);

# endif