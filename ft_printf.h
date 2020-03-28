/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:34:00 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/27 22:08:33 by saopaulo42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define SPECIFIER "dicspuxX%"
# define FLAGS "-0"
# define SPACE ' '
# define DOT '.'
# define MINUS 0
# define ZERO 1

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

int				ft_printf(const char *str, ...);
int				ft_strlen(char *s);
int				ft_putchar(char c);
void			ft_putstr(t_info *info, char *s);

int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa(int nb);
char			*ft_itoa_base(size_t value, int base, int alc);
void			ft_addpads(int *duration, int len, t_info *info, int pad);

void			ft_print_c(t_info *info, t_flags *flags);
void			ft_print_percent(t_info *info, t_flags *flags);
void			ft_print_u(t_info *info, t_flags *flags);
void			ft_print_di(t_info *info, t_flags *flags);
void			ft_print_x(t_info *info, t_flags *flags, int alphacase);
void			ft_print_s(t_info *info, t_flags *flags);
void			ft_print_p(t_info *info, t_flags *flags);

#endif
