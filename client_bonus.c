/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/06/03 18:56:12 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//iniatialize string and sends 8 bits of each characters in the string
//sends SIGUSR1 for '1' bits and SIGUSR2 for '0' bits
//if unable to send signal aknowledge that to user
//wait 1000 microseconds btw signals sent to ensure better communication

void	send_signals(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 0;
		c = *(unsigned char *)(str);
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
			usleep(1000);
		}
		str++;
	}
}

//handler function for received signal
//if receives any SIGUSR1 signal states message as aknowledged by server

void	handler(int signum)
{
	static int	message_printed = 0;

	if (!message_printed)
	{
		if (signum == SIGUSR1)
		{
			ft_printf("Message acknowledged by server.\n");
			message_printed = 1;
		}
	}
}

//checks for a valid PID

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

//main function receives PID and message as arguments
//check the number of arguments, valid PID and valid message
//configures sigaction and set handlers to receive confirmation
//uses send_signal functions to send string

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
	return (EXIT_SUCCESS);
}
