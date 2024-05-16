/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:05:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/16 16:52:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> // remove after testing and including libft functions

void	send_signals(char *message, int pid)
{
   int	i;
   int	shift;

   shift = -1;
   i = 0;
   while (message[i])
   {
   	while (++shift < 8)
   	{
   		if (message[i] & 0x80 >> shift)
         {
   			if (kill(pid, SIGUSR2) == -1)
               exit(1);
         }         
   		else
         {
            if (kill(pid, SIGUSR1) == -1)
               exit(1);
         }
   		usleep(3);
   	}
   	i++;
   }
}

int	main(int argc, char *argv[])
{
   int		pid;

   if (argc != 3)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   send_signals(argv[2], pid);
   return (0);
}
