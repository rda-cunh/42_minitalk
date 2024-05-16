/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/16 17:03:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

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
