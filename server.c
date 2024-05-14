/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/14 18:28:35 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

void    handler_sigusr1(int signum)
{
    (void)signum; 
    printf("1");
}

void    handler_sigusr2(int signum)
{
    (void)signum; 
    printf("0");
}

int main(void) 
{
    printf("PID = %d\n", getpid());
    signal(SIGUSR1, handler_sigusr1);
    signal(SIGUSR2, handler_sigusr2); 
    while (1)
        pause(); 
    return (0); 
}
