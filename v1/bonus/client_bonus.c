/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:25:38 by gamorcil          #+#    #+#             */
/*   Updated: 2025/07/01 15:25:38 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	flag = 0;

void	send_message(int pid, char *message)
{
	unsigned char	c;
	int				bits_i;
	int				i;

	i = 0;
	while (message[i] != '\0')
	{
		c = message[i];
		bits_i = 8;
		while (bits_i--)
		{
			flag = 0;
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!flag)
				pause();
			c <<= 1;
		}
		i++;
	}
}

int	check_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!strchr("1234567890", argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	signal_back(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Received SIGUSR1\n");
		flag = 1;
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Received SIGUSR2\n");
		flag = 1;
	}
}

void	handle_signal(void)
{
	struct sigaction	new_sig;

	new_sig.sa_handler = &signal_back;
	sigemptyset(&new_sig.sa_mask);
	new_sig.sa_flags = 0;
	if (sigaction(SIGUSR1, &new_sig, NULL) == -1)
		ft_printf("Error on sigaction");
	if (sigaction(SIGUSR2, &new_sig, NULL) == -1)
		ft_printf("Error on sigaction");
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf("Error\nUse the executable with the PID and the message\n");
		exit (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1 || check_num(argv[1]) == 1)
	{
		ft_printf("Wrong PID\n");
		exit (1);
	}
	ft_printf("Todo correcto\n");
	handle_signal();
	send_message(pid, argv[2]);
	return (0);
}
