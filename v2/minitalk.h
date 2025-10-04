/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:08:44 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/01 19:11:00 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>


//Server
typedef struct s_global
{
	int		client_pid;
	int		header_flag;
	int		str_flag;
	int     str_len;
    int     bit_index;
	int		str_index;
	int		current_letter;
    char    *str;
}	t_global;

void	client_finish(void);
void	set_signals(void);
void	handle_signal(int signum, siginfo_t *info, void *context);
void	set_str(int signum);
void	set_header(int signum);
//client

void    send_len(int str_len, int server_pid);
void	set_signal();
void	connect(int server_pid);
void	handle_signal_client(int sigum, siginfo_t *info, void *context);

#endif
