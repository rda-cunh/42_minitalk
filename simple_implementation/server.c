/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/20 18:21:31 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after changing printf for ft_printf

void    handler_sigusr(int signum)
{
    static unsigned char buff;
    static int  i; 

    buff |= (signum == SIGUSR1);
    i++;
    if (i == 8)
    {
        printf("%c", buff);
        i = 0;
        buff = 0;
    }
    else 
        buff <<= 1;
}

int main(void)
{
    printf("The PID server is: %d\n", getpid());
    signal(SIGUSR2, handler_sigusr);
    signal(SIGUSR1, handler_sigusr);
    while (1)
        pause();
    return (0);
}
