/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:00 by gariadno          #+#    #+#             */
/*   Updated: 2020/03/05 16:40:38 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{

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
/*   int i = 2;
   printf("|%d|		\n",	i++);
   printf("|%d|	\n",	i);
   printf("|%03d|	\n",	3);
   printf("|%-90.80d|	\n",	123456);
   
   printf("|%2d|	\n",	3*1000);
   printf("|%-2d|	\n",	3*1000);
   printf("|%.3d|	\n",	123456);
   
   printf("___________________\n\n");
   
   printf("|%s|		\n",	"ABCD");
   printf("|%9s|	\n",	"ABCD");
   printf("|%-9s|	\n",	"ABCD");
   printf("|%1s|	\n",	"ABCD");
   printf("|%1s|	\n",	"ABCD");
   
   printf("___________________\n\n");
*/   
   printf("|%5c|		\n",  'A');
   printf("|%-5c|		\n",  'B');
   printf("|%*c|      \n",  5,'C');
   printf("|%-*c|      \n",  5,'D');
   printf("|%*c|      \n",  -5,'D');
   
   
   printf("|%05c|      \n",  'X');

//   printf("len = %d", ft_printf("abcd\n"));
//   printf("|%.2147482999d|	\n",	7);
/*   
   
   printf("___________________\n\n");

   printf("|%30p|	\n",	p);
   printf("|%-30p|	\n",	p);
   printf("|%2p|	\n",	p);
   printf("|%-2p|	\n",	p);

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