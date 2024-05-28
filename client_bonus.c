/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:21 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/05/28 23:31:50 by rda-cunh         ###   ########.fr       */
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
