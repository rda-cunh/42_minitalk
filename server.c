/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/19 17:10:39 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

//this function is called in case of an error occurred in a kill() system call

void	error_handling(int pid, char *str)
{
	if 
}


void handler_sigusr(int signum) 
{
    static char c = 0xFF;
    static int  bits = 0; 
    
    if (signum == SIGUSR1)
    {
        printf("0");
        c ^= 0x80 >> bits; 
    }
    else if (signum == SIGUSR2)
    {
        printf("1"); 
        c |= 0x80 >> bits; 
    }
    bits++;
    if (bits == 8)
    {
        printf("-> %c\n", c);
        bits = 0;
        c = 0xFF; 
    }
}

// main function of the server 

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
