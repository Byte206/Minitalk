/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:03:52 by gamorcil          #+#    #+#             */
/*   Updated: 2025/06/30 22:03:52 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stddef.h>

int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char	*str);

typedef struct s_mini
{
	int	server_pid;
	int	client_pid;
}	t_mini;

#endif