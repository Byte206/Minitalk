/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:53:35 by gamorcil          #+#    #+#             */
/*   Updated: 2025/05/29 19:53:35 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_format(char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'p')
		return (ft_put_ptr(va_arg(ap, void *)));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'x')
		return (ft_put_hex(va_arg(ap, unsigned int), 1));
	else if (format == 'X')
		return (ft_put_hex(va_arg(ap, unsigned int), 0));
	return (1);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += print_format(str[i + 1], ap);
			i++;
		}
		else
		{
			length += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (length);
}
	/*
int main()
{
	#include <stdio.h>

    int nbr = 1234;
    unsigned int n = 4294967295;
    char str[] = "que tal";
    ft_printf("Hola ");
    ft_printf("%s ",str);
    ft_printf("%d\n", nbr);
    ft_printf("str: %p\n", str);
    ft_printf("unsgined: %u\n", n);
    ft_printf("%x\n", 255);    // Imprime: ff
    ft_printf("%X\n", 255);    // Imprime: FF
    ft_printf("%x\n", 16);     // Imprime: 10
    ft_printf("%X\n", 16);     // Imprime: 10
    ft_printf("%x\n", 0);      // Imprime: 0
    ft_printf("%X\n", 171);    // Imprime: AB 
	ft_printf(" %p ", -1);
	printf(" %p ", -1);
	ft_printf(" NULL %s NULL", NULL);
	ft_printf("\n");
	printf(" NULL %s NULL", NULL);
	
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);

}*/
