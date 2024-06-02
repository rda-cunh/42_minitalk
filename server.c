/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/06/02 17:59:59 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//signal handler function
//shift the character left and add a bit based on the signal received
//increment bit counter i
//if the 8 bits are received print the character

#include "minitalk.h"

void	handler(int signum)
{
	static unsigned char	c = 0;
	static int				i = 0;

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
	}
}

//print server PID
//sets signals handlers for SIGUSR1 and SIGUSR2 using signal function
//wait for signals using an infinite loop

int	main(void)
{
	ft_printf("My PID is: %d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
		pause();
	}
	return (0);
}
