/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/20 16:39:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after changing printf for ft_printf
#include <stdlib.h> // remove after changing atoi for ft_atoi

void    send_signals(int pid, unsigned char octet)
{
    int i;
    unsigned char   octet_tmp;

    octet_tmp = octet;
    i = 8;
    while (i-- > 0)
    {
        octet_tmp = octet >> i;
        if (octet_tmp % 2 == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
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
        printf("Arguments are not correct\n");
        return (1);
    }
    pid = atoi(argv[2]);
    str_to_send = argv[2];
    i = 0;
    while (str_to_send[i])
    {
        send_signals(pid, (unsigned char)str_to_send[i]);
        i++;
    }
    printf("Number of characters sent: %d", i);
    return (0);
}

