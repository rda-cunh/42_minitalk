/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/23 13:03:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
    ft_printf("My PID is: %d\n", getpid());
    signal(SIGUSR2, handler);
    signal(SIGUSR1, handler);
    while (1)
    {
        pause(); 
    }
    return (0);
}
