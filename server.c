/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:02:58 by gamorcil          #+#    #+#             */
/*   Updated: 2025/06/30 22:02:58 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_receive(int signum, siginfo_t *info, void *ucontent)
{
	static int				bits_i = -1;
	static unsigned char	c = 0;

	(void)ucontent;
	if (bits_i < 0)
		bits_i = 7;
	if (signum == SIGUSR1)
	{
		c |= (1 << bits_i);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
	bits_i--;
	if (bits_i < 0)
	{
		write(1, &c, 1);
		c = 0;
	}
}

void	handle_signal(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &message_receive;
	sa_newsig.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa_newsig, NULL) == -1))
		{
			ft_printf("Error at sigaction");
			return ;
		}
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		ft_printf ("ERROR!\nDo not use the ejecutable with arguements\n");
		ft_printf("Dont type %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	ft_printf ("PID:%d\n", getpid());
	while (1)
	{
		handle_signal();
	}
	return (0);
}
