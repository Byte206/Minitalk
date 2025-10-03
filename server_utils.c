/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:57:14 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/03 21:09:13 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern t_global	g_server_data;

void	client_finish(void)
{
	ft_printf("%s\n", g_server_data.str);
	free(g_server_data.str);
	usleep(500);
	kill(g_server_data.client_pid, SIGUSR1);
	ft_memset(&g_server_data, 0, sizeof(t_global));
}
