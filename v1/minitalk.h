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
# include <string.h>

int		check_num(char *argv);
void	message_receive(int signum, siginfo_t *info, void *ucontent);
void	handle_signal(void);
void	send_message(int pid, char *message);

#endif
