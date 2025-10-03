/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:08:02 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/01 19:08:36 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_flag;

void	send_len(int str_len, int server_pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		g_flag = 0;
		if (str_len & (1ULL << i))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_printf("Error sending signal\n");
			//ft_printf("SIGUSR1\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_printf("Error sending signal\n");
			//ft_printf("SIGUSR2\n");
		}
		while (!g_flag)
			pause();
		i--;
	}
}

void	send_str(int server_pid, char *str, int str_len)
{
	int	i;
	int	bit;

	i = 0;
	while (i < str_len)
	{
		bit = 7;
		while (bit >= 0)
		{
			g_flag = 0;
			if (str[i] & (1 << bit))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (!g_flag)
				pause();
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	str_len;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [SERVER_PID] [MESSAGE]\n");
		return (1);
	}
	ft_printf("Client PID:%d\n", getpid());
	server_pid = ft_atoi(argv[1]);
	str_len = ft_strlen(argv[2]);
	g_flag = 0;
	set_signal();
	connect(server_pid);
	send_len(str_len, server_pid);
	send_str(server_pid, argv[2], str_len);
}
