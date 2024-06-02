/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/06/02 18:13:42 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//sends the signals corresponding to each bit of the characters in the string
//sends SIGUSR1 for '1' bits and SIGUSR2 for '0' bits
//wait 1000 microseconds btw signals sent to ensure better communication

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
		usleep(1000);
		i++;
	}
}

//main function receives PID and message as arguments
//check the number of arguments
//starts a loop to send each character to server

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;
	int		i;

	if (argc != 3)
	{
		ft_printf("Number of arguments provided is not correct.\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	i = 0;
	while (str_to_send[i])
	{
		send_signals(pid, (unsigned char)str_to_send[i]);
		i++;
	}
	ft_printf("Number of characters sent: %d\n", i);
	return (0);
}
