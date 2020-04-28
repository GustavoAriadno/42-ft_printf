/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:33:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/01 19:34:32 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned long int n)
{
	unsigned int	i;
	unsigned char	*desty;
	unsigned char	*ori;

	desty = (unsigned char *)dst;
	ori = (unsigned char *)src;
	i = 0;
	while (i < n && ori[i] != (unsigned char)c)
	{
		desty[i] = ori[i];
		i++;
	}
	if (ori[i] == (unsigned char)c)
	{
		desty[i] = ori[i];
		return (&desty[i + 1]);
	}
	return (0);
}
