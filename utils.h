/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:15:39 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/23 13:25:58 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

// #define BUFFER_SIZE 1024

void	send_bit(int pid, char bit);
void	send_char(int pid, char c);
void	handle_signal(int sig, siginfo_t *info, void *context);
long	ft_atol(const char *str);

#endif
