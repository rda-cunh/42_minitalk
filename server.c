/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/17 19:47:24 by rda-cunh         ###   ########.fr       */
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

int main(void) 
{
    
	pid_t   pid;
    
    pid = getpid();
    printf("PID = %d\n", pid);
    
    // Set up signal handlers
    signal(SIGUSR1, handler_sigusr);
    signal(SIGUSR2, handler_sigusr);

    // Enter infinite loop waiting for signals
    while (1)
        pause();
    return 0;
}
