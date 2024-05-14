/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/15 00:05:02 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

void handler_sigusr1(int signum) 
{
    (void)signum;
    printf("1");
    fflush(stdout);
}

void handler_sigusr2(int signum) 
{
    (void)signum;
    printf("0");
    fflush(stdout);
}

int main(void) 
{
    printf("PID = %d\n", getpid());
    
    // Set up signal handlers
    signal(SIGUSR1, handler_sigusr1);
    signal(SIGUSR2, handler_sigusr2);

    // Enter infinite loop waiting for signals
    while (1)
        pause();

    return 0;
}
