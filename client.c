/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:05:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/14 18:46:29 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

void    signal_sender(char *message, int pid)
{
    int i;
    int bitshift;

    i = 0; 
    bitshift = -1;
    while (message[i])
    {
        while(++bitshift < 8)
        {
            if (message[i] & 0x80 >> bitshift)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(3);
        }
        i++;
    }  
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        printf("Client: invalid argument.\n");
        exit(EXIT_FAILURE);
    }
    pid = atoi(argv[1]);
    signal_sender(argv[2], pid);
    return (0); 
}
