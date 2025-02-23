/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:15:07 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/23 12:23:55 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_bit(int pid, char bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10000);
}


void    send_char(int pid, char c)
{
	int    i;

    i = 0;
    while (i < 8)
    {
        send_bit(pid, (c >> i) & 1);
        i++;
    }
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483648)
			return (2147483649);
		str++;
	}
	return (result * sign);
}
