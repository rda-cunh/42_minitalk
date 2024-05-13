/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:06:09 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/13 13:03:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

void    signal_handler(int signum)
{
    (void)signum; 
    printf("Server: signal received from client.\n");
}

int main(void)
{
    printf("PID = %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    while (1)
        pause(); 
    return (0); 
}
