/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:34:00 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/07 16:23:09 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define SPECIFIER "dicspuxX%"
# define FLAGS "-0"
# define SPACE ' '
# define DOT '.'

typedef struct	s_flags
{
	int	flag;
	int	width;
	int	dot;
	int	asterisk;
	int	precision;
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
int		ft_miniatoi(t_info *info);
int		ft_isdigit(int c);
void	ft_print_c(t_info *info, t_flags *flags);
void	ft_print_percent(t_info *info, t_flags *flags);
void	ft_print_u(t_info *info, t_flags *flags);

# endif