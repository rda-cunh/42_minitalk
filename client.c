/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:05:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/13 16:43:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

int main(int argc, char **argv)
{
    int i;
    int bitshift;
    char    word; 
    
    if (argc != 2)
        return (1); 
    word = argv[1][0];
    bitshift = -1; 
    while (++bitshift < 8)
    {
        if (word & 0x80 >> bitshift)
            printf("1");
        
    } 
}

/*
int main(int argc, char **argv)
{
    int pid;

    if (argc != 2)
    {
        printf("Client: invalid argument.\n");
        exit(EXIT_FAILURE);
    }
    pid = atoi(argv[1]);
    kill(pid, SIGUSR1);
    return (0); 
}
*/
