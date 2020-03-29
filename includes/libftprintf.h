/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:23:50 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/29 18:32:28 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define LOWER_CASE	'a'
# define UPPER_CASE	'A'
# define SPECIFIER	"dicspuxX%"
# define STR_NULL	"(null)"
# define ASTERISK	'*'
# define SPACE		' '
# define MINUS		'-'
# define ZERO		'0'
# define DOT		'.'

# define DECIMAL	'd'
# define INTEGER	'i'
# define UNSIGNED	'u'
# define CHAR		'c'
# define STRING		's'
# define POINTER	'p'
# define LOW_HEXA	'x'
# define UP_HEXA	'X'
# define PERCENT	'%'

typedef struct	s_flags
{
	int	flag;
	int	width;
	int	precision;
}				t_flags;

typedef struct	s_info
{
	const char	*str;
	va_list		args;
	int			len;
	int			i;
}				t_info;

int				ft_putchar(char c);
int				ft_strlen(char *s);
int				ft_printf(const char *str, ...);
void			ft_putstr(t_info *info, char *s);

char			*ft_itoa(int nb);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa_base(size_t nb, int base, char alpha_case);
void			ft_addpads(int duration, int len, t_info *info, int pad);

void			ft_print_s(t_info *info, t_flags *flags);
void			ft_print_u(t_info *info, t_flags *flags);
void			ft_print_c(t_info *info, t_flags *flags);
void			ft_print_p(t_info *info, t_flags *flags);
void			ft_print_di(t_info *info, t_flags *flags);
void			ft_print_percent(t_info *info, t_flags *flags);
void			ft_print_x(t_info *info, t_flags *flags, char alpha_case);

#endif
