/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:37:58 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/18 14:51:54 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "./libft/libft.h"

static void	extra_action(siginfo_t *info, t_vector *temp)
{
	kill(info->si_pid, SIGUSR1);
	write(STDOUT_FILENO, temp->str, temp->capacity);
	free(temp->str);
	temp->str = NULL;
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				count = 8;
	static t_vector			temp;
	static char				msg = '\0';

	(void)context;
	msg = msg | (sig == SIGUSR2);
	count--;
	if (count == 0)
	{
		if (ft_appendchar(&temp, msg) == 1)
		{
			write(STDOUT_FILENO, "Malloc failed\n", 15);
			exit (1);
		}
		if (msg == '\0')
			extra_action(info, &temp);
		count = 8;
		msg = '\0';
	}
	msg <<= 1;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sig;

	pid = getpid();
	ft_putstr_fd("Server PID:  ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	s_sig.sa_sigaction = &action;
	s_sig.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&s_sig.sa_mask);
	if (sigaction(SIGUSR1, &s_sig, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &s_sig, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
