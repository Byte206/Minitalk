/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:23:39 by gamorcil          #+#    #+#             */
/*   Updated: 2025/06/04 16:23:39 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(uintptr_t nbr)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (nbr >= 16)
		put_hex(nbr / 16);
	write(1, &hex_digits[nbr % 16], 1);
}

int	ft_count_hex_digits(uintptr_t addr)
{
	int			count;

	count = 0;
	while (addr > 0)
	{
		addr /= 16;
		count++;
	}
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	intptr_t	addr;
	int			i;

	i = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (uintptr_t)ptr;
	write(1, "0x", 2);
	i += 2;
	if (addr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		i += ft_count_hex_digits(addr);
		put_hex(addr);
	}
	return (i);
}
