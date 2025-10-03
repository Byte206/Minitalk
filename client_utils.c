/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:49:35 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/03 20:08:01 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern int	g_flag;

void	handle_signal_client(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		g_flag = 1;
	}
}

void	connect(int server_pid)
{
	if (kill(server_pid, SIGUSR1) == -1)
	{
		ft_printf("Error connecting to server\n");
	}
	while (!g_flag)
	{
		ft_printf("Waiting server signal\n");
		pause();
	}
	ft_printf("Server connected\n");
}

void	set_signal(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal_client;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
