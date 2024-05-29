/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/29 11:18:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_printf("Unable to send SIGUSR2\n");
}

int	main(void)
{
	struct sigaction	sa_signal;

	ft_printf("My PID is: %d\n", getpid());
	sa_signal.sa_sigaction = &handler;
	sa_signal.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_signal.sa_mask);
	if (sigaction(SIGUSR2, &sa_signal, NULL) == -1)
	{
		ft_printf("Error setting handler for SIGUSR2");
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR1, &sa_signal, NULL) == -1)
	{
		ft_printf("Error setting handler for SIGUSR1")
		return (EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
