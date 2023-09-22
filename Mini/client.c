/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:43:58 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/18 18:10:08 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

#define TIMEOUT 5000

int	g_bitcheck = 0;

// function checks if SIGUSR2 was reached, returning a 1
// else, write msg received by SIGUSR1
void	sig_confirm(int sig)
{
	if (sig == SIGUSR2)
		g_bitcheck = 1;
	else if (sig == SIGUSR1)
		write(STDOUT_FILENO, "Msg received\n", 14);
}

// simulates a time out from server, 
// giving an x amount o time to show if msg was received or not
void	time_check(void)
{
	int	t;

	t = 0;
	while (1)
	{
		t++;
		if (t == TIMEOUT)
		{
			write(STDOUT_FILENO, "Server Time Out\n", 17);
			exit(1);
		}
		if (g_bitcheck == 1)
			break ;
		usleep(20);
	}
	g_bitcheck = 0;
}

// read and sends a signal depending the bit num, 1 ou 0
void	bit_read(int n, int count, int pid)
{
	int	kc;

	kc = 0;
	if (count == 0)
		return ;
	bit_read(n >> 1, count -1, pid);
	if (!(n & 1))
		kc = kill(pid, SIGUSR1);
	else
		kc = kill(pid, SIGUSR2);
	if (kc < 0)
	{
		write(STDERR_FILENO, "Wrong PID", 10);
		exit(EXIT_FAILURE);
	}
	time_check();
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		return (write(STDERR_FILENO, "wrong imput", 12));
	else if (ft_atoi(argv[1]) <= 0)
		return (write(STDERR_FILENO, "PID error", 10));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_confirm);
	signal(SIGUSR2, sig_confirm);
	while (argv[2][i] != '\0')
	{
		bit_read(argv[2][i], 8, pid);
		i++;
	}
	bit_read('\n', 8, pid);
	bit_read(argv[2][i], 8, pid);
	return (0);
}
