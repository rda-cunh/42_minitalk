/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/23 12:36:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test
#include "minitalk.h"
#include <stdio.h> // remove after changing printf for ft_printf

void    handler(int signum)
{
    static unsigned char c = 0;
    static int  i = 0; 

    if (signum == SIGUSR2)
        c = c << 1;
    else if (signum == SIGUSR1)
        c = (c << 1) | 0b00000001;
    i++;
    if (i == 8)
    {
        write(STDOUT_FILENO, &c, 1);
        i = 0;
        c = 0; 
    }
}

int main(void)
{
    printf("My PID is: %d\n", getpid());
    while (1)
    {
        signal(SIGUSR2, handler);
        signal(SIGUSR1, handler);
    }
    return (0);
}
