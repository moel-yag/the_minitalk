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

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static unsigned char current_byte = 0;  // To store the current byte being reconstructed
static int bit_count = 0;  // To track how many bits we've received (0 to 7)

// Signal handler function for SIGUSR1 and SIGUSR2
void handle_signal(int sig)
{
    // Shift the current byte left to make space for the next bit
    current_byte <<= 1;

    // If the signal is SIGUSR1, set the least significant bit to 0
    if (sig == SIGUSR1)
    {
        current_byte |= 0;  // No change, but makes the code clearer
    }
    // If the signal is SIGUSR2, set the least significant bit to 1
    else if (sig == SIGUSR2)
    {
        current_byte |= 1;
    }

    // After receiving 8 bits (one byte), print the character
    if (++bit_count == 8)
    {
        write(1, &current_byte, 1);  // Print the byte (character)

        // Reset for the next byte
        bit_count = 0;
        current_byte = 0;
    }
}

int main()
{
    struct sigaction sa_usr1, sa_usr2;

    // Initialize sigaction struct for SIGUSR1
    sa_usr1.sa_handler = handle_signal;  // Set the handler function
    sa_usr1.sa_flags = 0;  // No flags
    sigemptyset(&sa_usr1.sa_mask);  // Clear the signal mask (no blocked signals)
    
    // Initialize sigaction struct for SIGUSR2
    sa_usr2.sa_handler = handle_signal;  // Set the same handler function
    sa_usr2.sa_flags = 0;  // No flags
    sigemptyset(&sa_usr2.sa_mask);  // Clear the signal mask (no blocked signals)

	ft_printf("Process PID: %d\n", getpid());
    // Set the handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
    {
        perror("sigaction(SIGUSR1) failed");
        return 1;
    }

    // Set the handler for SIGUSR2
    if (sigaction(SIGUSR2, &sa_usr2, NULL) == -1)
    {
        perror("sigaction(SIGUSR2) failed");
        return 1;
    }

    // Wait for signals indefinitely
    while (1)
    {
        pause();  // This will make the server wait for signals
    }

    return 0;
}


// static void	handle_signal(int sig, siginfo_t *info, void *context)
// {
// 	static int				bit_count = 0;
// 	static unsigned char	c = 0;

// 	(void)context;
// 	if (sig == SIGUSR1)
// 		c |= (1 << bit_count);
// 	bit_count++;
// 	if (bit_count == 8)
// 	{
// 		write(1, &c, 1);
// 		bit_count = 0;
// 		c = 0;
// 	}
// 	kill(info->si_pid, SIGUSR1);
// }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	ft_printf("Server PID: %d\n", getpid());
// 	sa.sa_sigaction = handle_signal;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	while (1)
// 		pause();
// 	return (0);
// }
