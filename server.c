/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:00:17 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/01 20:00:17 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_global	g_server_data;

void	set_header(int signum)
{
	int	bit;

	bit = (signum == SIGUSR2);
	if (g_server_data.bit_index < 32)
	{
		g_server_data.str_len |= (bit << (31 - g_server_data.bit_index));
		g_server_data.bit_index++;
	}
	if (g_server_data.bit_index == 32)
	{
		ft_printf("String len: %d\n", g_server_data.str_len);
		g_server_data.str = malloc(g_server_data.str_len + 1);
		if (!g_server_data.str)
			exit(1);
		g_server_data.str[g_server_data.str_len] = '\0';
		g_server_data.header_flag = 0;
		g_server_data.str_flag = 1;
		g_server_data.bit_index = 0;
	}
	kill(g_server_data.client_pid, SIGUSR1);
}

void	set_str(int signum)
{
	int			bit;
	static int	str_index;
	static int	letter;

	bit = (signum == SIGUSR2);
	if (g_server_data.bit_index % 8 < 8)
	{
		letter |= (bit << (7 - (g_server_data.bit_index % 8)));
		g_server_data.bit_index++;
	}
	if (g_server_data.bit_index % 8 == 0)
	{
		g_server_data.str[str_index] = letter;
		letter = 0;
		str_index++;
	}
	if (g_server_data.bit_index / 8 == g_server_data.str_len)
	{
		ft_printf("%s\n", g_server_data.str);
		free(g_server_data.str);
		ft_memset(&g_server_data, 0, sizeof(t_global));
		str_index = 0;
		letter = 0;
	}
	kill(g_server_data.client_pid, SIGUSR1);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server_data.client_pid == 0)
	{
		g_server_data.client_pid = info->si_pid;
		g_server_data.header_flag = 1;
		kill(g_server_data.client_pid, SIGUSR1);
		return ;
	}
	if (g_server_data.header_flag == 1)
		set_header(signum);
	else if (g_server_data.str_flag == 1)
		set_str(signum);
}

void	set_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	ft_memset(&g_server_data, 0, sizeof(t_global));
	set_signals();
	while (1)
		pause();
	return (0);
}
