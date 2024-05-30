/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/30 17:48:35 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		i = 0;
		c = *(str);
		while (i < 8)
		{
			if (c & (0b10000000 >> i))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Unable to send SIGUSR1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Unable to send SIGUSR2\n");
			}
			i++;
			usleep(500);
		}
		str++;
	}
}

void	handler(int signum)
{
	static int	message_printed = 0;

	if (!message_printed)
	{
		if (signum == SIGUSR1)
		{
			ft_printf("Message sent and received by server.\n");
			message_printed = 1;
		}
	}
}

int	is_valid_pid(const char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_signal;

	if (argc != 3 || argv[2][0] == '\0' || !is_valid_pid(argv[1]))
	{
		ft_printf("Incorrect number of arguments, empty message"
			" or invalid PID.\n");
		return (EXIT_FAILURE);
	}
	sa_signal.sa_handler = &handler;
	sa_signal.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_signal.sa_mask);
	if (sigaction(SIGUSR2, &sa_signal, NULL) == -1)
	{
		ft_printf("Error setting handler for SIGUSR2\n");
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR1, &sa_signal, NULL) == -1)
	{
		ft_printf("Error setting handler for SIGUSR1\n");
		return (EXIT_FAILURE);
	}
	send_signals(ft_atoi(argv[1]), argv[2]);
//	ft_printf("Message sent successfully.\n");
	return (EXIT_SUCCESS);
}
