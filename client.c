/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:14:46 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/23 12:14:48 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_bit_of_byte(unsigned char my_bit, int pid)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (my_bit >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

void	send_string_bits(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit_of_byte(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atol(av[1]);
	if (kill(pid, 0) == -1)
		return (1);
	send_string_bits(av[2], pid);
}
