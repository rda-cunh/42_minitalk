/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/29 13:13:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, unsigned char octet)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (octet & (0b10000000 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int is_valid_pid(const char *pid)
{
    int i = 0;
    while (pid[i])
    {
        if (!ft_isdigit(pid[i]))
            return (0);
        i++;
    }
    return (1);
}


int	main(int argc, char **argv)
{
	int					i;
	struct sigaction	sa_signal;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0' || !is_valid_pid(argv[1])) 
	{
		ft_printf("Incorrect number of arguments, empty message or invalid PID.\n");
		return (EXIT_FAILURE);
	}
	else
	
	while (str_to_send[i])
	{
		send_signals(pid, (unsigned char)str_to_send[i]);
		i++;
	}
	ft_printf("Number of characters sent: %d\n", i);
	return (EXIT_SUCCESS);
}
