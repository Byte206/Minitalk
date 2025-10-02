/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:57:37 by gamorcil          #+#    #+#             */
/*   Updated: 2025/05/29 19:57:37 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
int		ft_putstr(char *str);
int		print_format(char format, va_list ap);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_put_ptr(void *ptr);
int		ft_put_hex(unsigned long nbr, int lowercase);
int		ft_putnbr_u(unsigned int nbr);
void	put_hex(uintptr_t nbr);
int		ft_count_hex_digits(uintptr_t addr);

#endif