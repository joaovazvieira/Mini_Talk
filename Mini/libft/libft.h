/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:04:25 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/15 12:28:27 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_strlcat(char *dst, char src, size_t dstsize);
size_t		ft_strlen(const char *s);

typedef struct s_vector
{
	int		size;
	int		capacity;
	char	*str;
}				t_vector;

int			ft_appendchar(t_vector *buff, char new_char);

#endif