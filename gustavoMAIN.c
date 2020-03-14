/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gustavoMAIN.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:00 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/14 20:01:23 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
/*
void	ft_addpads(int *duration, int len)
{
	while ((*duration)-- > len)
		ft_putchar('x');
}
*/
int main()
{
  /* 
   t_flags fl;
   
   fl.flag = -1;
	fl.width = -1;
	fl.dot = 40;
	fl.precision = -1;
	fl.specifier = -1;

   //printf("%d\n", fl.dot);
   ft_addpads(&(fl.dot), 20);
   printf("%d", fl.dot);
*/
//    int *p;
//    int x;

//    p = &x;
//    x = 84854;
//    printf("abcs");
/*
   printf ("Char:    				\n%c %c \n____________\n\n", 'a', 65);
   printf("Pointer:                 \n%p \n___________\n\n", l);
   printf ("Decimals:				\n%d %ld\n_____________\n\n", 1977, 650000L);
   printf ("Preceding with blanks:	\n%10d \n______________\n\n", 1977);
   printf ("Preceding with zeros:	\n%010d \n_____________\n\n", 1977);
   printf ("Some different radices:	\n%d %x %o %#x %#o \n____________\n\n", 100, 100, 100, 100, 100);
   printf ("floats:					\n%4.2f %+.0e %E \n__________\n\n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick:			\n%*d \n___________\n\n", 5, 10);
   printf ("%s \n", "				\nA string\n");*/

   //%[Flags][Width][.Precisioon]Specifier
/*   
   printf("len == %d\n", ft_printf("\n|%s|	   	\n",	"));
   printf("len == %d\n", ft_printf("\n|%10s|		   \n",	"0123456789"));
   printf("len == %d\n", ft_printf("\n|%020s|		\n",	"0123456789"));
   printf("len == %d\n", ft_printf("\n|%-10.5s|		\n",	"0123456789"));
   printf("len == %d\n", ft_printf("\n|%.5s|		\n",	"0123456789"));
   printf("len == %d\n", ft_printf("\n|%-20.5s|  	\n",	"0123456789"));
   printf("len == %d\n", ft_printf("\n|%010.5s|  	\n",	"A123456789"));
*/
/*
   printf("len == %d\n", ft_printf("\n|%2s|	   	\n",	"A123456789"));
   printf("len == %d\n", ft_printf("\n|%-2s|	   	\n",	"A123456789"));
   printf("len == %d\n", ft_printf("\n|%2.0s|	   	\n",	"A123456789"));
   printf("len == %d\n", ft_printf("\n|%-2.0s|	   	\n",	"A123456789"));
*/
//   printf("|%u|	\n",	2147480000);
/* 
   TESTAR ENDEREÇO DE ELEMENTO DA STRUCT PARA FT
   

   printf("___________________\n\n");
   
   printf("|%s|		\n",	"ABCD");
   printf("|%9s|	\n",	"ABCD");
   printf("|%-9s|	\n",	"ABCD");
   printf("|%1s|	\n",	"ABCD");
   printf("|%1s|	\n",	"ABCD");
*//*
   printf("len == %d\n\n", printf	   ("|%d|\n", -123456));
   printf("______________________________\n");
   printf("len == %d\n\n", ft_printf	("|%d|\n", -123456));
   
	printf("len == %d\n\n", printf	   ("|%-10d|\n", -123456));
   printf("______________________________\n");
   printf("len == %d\n\n", ft_printf	("|%-10d|\n", -123456));
   
   printf("len == %d\n\n", printf	   ("|%10d|\n", -123456));
   printf("______________________________\n");
   printf("len == %d\n\n", ft_printf	("|%10d|\n", -123456));
   
   printf("len == %d\n\n", printf      ("|%11.10d|\n", -123456789));
   printf("len == %d\n\n", ft_printf	("|%11.10d|\n", -123456789));
   
   printf("______________________________\n");
	printf("len == %d\n\n", printf	   ("|%20.10d|\n", -123456789));
   printf("len == %d\n\n", ft_printf	("|%20.10d|\n", -123456789));
   */
   printf("______________________________\n");
	printf("len == %d\n\n", printf	   ("|%0*d|\n", 7, -54));
   printf("len == %d\n\n", ft_printf	("|%0*d|\n", 7, -54));
/*   
   printf("___________________\n\n");

   
   printf("|%5%|		\n");
   printf("|%-5%|		\n");
   printf("|%05%|		\n");
   printf("|%*%|      \n",  5);
   printf("|%-*%|      \n",  5);
   printf("|%*%|        \n",  -5);
   
   printf("\n\n");

   printf("|%.80%|		\n");
   printf("|%-5.20%|		\n");
*/
//   printf("\nlen == %d\n", ft_printf("|%%|\n"));
   
//   printf("\nlen == %d\n", printf("|%5%|\n"));
//   printf("|%02c|      \n",  'X');

//   printf("len = %d", ft_printf("abcd\n"));
//   printf("|%.2147482999d|	\n",	7);
/*   
   
   printf("___________________\n\n");
*/
/*
   int p;

   p = 2;
   printf("len == %d\n", ft_printf("\n|%p|	   	\n",	&p));
   printf("len == %d\n", ft_printf("\n|%40p|		   \n",	&p));
   printf("len == %d\n", ft_printf("\n|%080p|		\n",	&p));
   printf("len == %d\n", ft_printf("\n|%080.50p|		\n",	&p));
   printf("len == %d\n", ft_printf("\n|%40.20p|  	\n",	&p));
   printf("len == %d\n", ft_printf("\n|%-40.20p|		\n",	&p));
   printf("len == %d\n", ft_printf("\n|%020.5p|  	\n",	&p));
*/

/*
   int a;

   a = 2;
   printf("\n%s", "TESTE COM P: \n");
   
   printf   ("\n|%-20p|\n", &a);
   ft_printf("\n|%-20p|\n", &a);
   

   printf   ("\n__________\n");
   printf   ("\n|%*p|\n", -20, &a);
   ft_printf("\n|%*p|\n", -20, &a);
   

   printf   ("\n__________\n");
   printf   ("\n|%p|\n", &a);
   ft_printf("\n|%p|\n", &a);
   
   
   printf   ("\n__________\n");
   printf   ("\n|%15p|\n", &a);
   ft_printf("\n|%15p|\n", &a);
*/
   
/*
   printf("___________________\n\n");
   
   printf("|%X|		\n",	10);
   printf("|%05X|	\n",	10);
   printf("|%-5X|	\n",	10);
   printf("|%1X|	\n",	10);
*/ 
   return 0;
}
/*
d  =  decimal
i  =  d
s  =  string
c  =  char
p  =  pointer adrres
u  =  unsigned decimal
x  =  unsigned HEXAdecimal
X  =  unsigned HEXAdecimal (UPPER)
%  =  %
_______________
-  =  left-justify
0  =  puts-zero-in-left
.  =  
*  =  
*/