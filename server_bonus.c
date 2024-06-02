/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/06/02 18:26:06 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//signal handler function
//shift the character left and add a bit based on the signal received
//increment bit counter
//if 8 bits are received print the character
//send aknowledgement signal back to the client

void	handler(int signum, siginfo_t *info, void *content)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)content;
	if (signum == SIGUSR2)
		c = c << 1;
	else if (signum == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Unable to send SIGUSR1\n");
		return ;
	}
}

//print server PID
//configures sigaction handler funtion
//sets signals handlers for SIGUSR1 and SIGUSR2 
//wait for signals using an infinite loop

int	main(void)
{
	struct sigaction	sa_signal;

	ft_printf("My PID is: %d\n", getpid());
	sa_signal.sa_sigaction = &handler;
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
	while (1)
	{
		pause();
	}
	return (0);
}
