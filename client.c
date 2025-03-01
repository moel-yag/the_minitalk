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

void    conv_bit(unsigned char my_bit, int pid)
{
    int bit;
    int i = 7;

    while (i>= 0)
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

void    send_bit(char *str, int pid)
{
    int i;

    i = 0;
    while (str[i])
    {
        conv_bit(str[i], pid);
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    if (ac != 3)
        return (0);
    pid = ft_atol(av[1]);
    send_bit(av[2], pid);
}