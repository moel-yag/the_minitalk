/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:14:32 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/23 12:14:33 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_data	g_data;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_data.res <<= 1;
		g_data.counter++;
	}
	else if (sig == SIGUSR2)
	{
		g_data.res <<= 1;
		g_data.res |= 1;
		g_data.counter++;
	}

	if (g_data.counter == 8)
	{
		write(1, &g_data.res, 1);
		g_data.counter = 0;
		g_data.res = 0;
	}
}

int	main()
{
	int	pid;

	pid = 0;
	g_data.res = 0;
	g_data.counter = 0;
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while(1);
}