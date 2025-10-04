/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:29:07 by gamorcil          #+#    #+#             */
/*   Updated: 2025/06/04 15:29:07 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putchar(nbr % 10 + '0');
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

int	ft_putnbr_u(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr > 9)
		i += ft_putnbr_u(nbr / 10);
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}

int	ft_put_hex(unsigned long nbr, int lowercase)
{
	char	*hex_digits;
	int		i;

	i = 0;
	if (lowercase)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
		i += ft_put_hex(nbr / 16, lowercase);
	write(1, &hex_digits[nbr % 16], 1);
	i++;
	return (i);
}
