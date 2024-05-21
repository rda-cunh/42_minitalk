/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 17:18:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after changing printf for ft_printf
#include <stdlib.h> // remove after changing atoi for ft_atoi

void    send_signals(int pid, unsigned char octet)
{
    int i;

    i = 8;
    while (i-- > 0)
    {
        if (octet & (1 << i))
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                perror("Error sending SIGUSR1");
                exit(1);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                perror("Error sending SIGUSR2");
                exit(1);
            }
        }
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    int pid;
    char    *str_to_send;
    int i;

    if (argc != 3)
    {
        printf("Number of arguments provided is not correct.\n");
        return (1);
    }
    pid = atoi(argv[1]);
    str_to_send = argv[2];
    i = 0;
    while (str_to_send[i])
    {
        send_signals(pid, (unsigned char)str_to_send[i]);
        i++;
    }
    printf("Number of characters sent: %d\n", i);
    return (0);
}

