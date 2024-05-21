/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/05/20 13:16:32 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/20 18:21:31 by rda-cunh         ###   ########.fr       */
=======
/*   Created: 2024/05/20 13:16:32 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 16:41:44 by codespace        ###   ########.fr       */
>>>>>>> a602df1 (new)
/*                                                                            */
/* ************************************************************************** */

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
        printf("%c", c);
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
