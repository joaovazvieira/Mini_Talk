/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:56:17 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/15 12:04:30 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	extra_malloc(t_vector *buff, char *temp, char new_char)
{
	temp = malloc(buff->size * 2);
	if (!temp)
		return ;
	ft_strlcpy(temp, buff->str, buff->capacity);
	free(buff->str);
	buff->str = temp;
	buff->size *= 2;
	buff->str[buff->capacity] = new_char;
	buff->capacity++;
}

int	ft_appendchar(t_vector *buff, char new_char)
{
	char	*temp;

	if (!buff->str)
	{
		buff->str = malloc(256 * sizeof(char));
		if (!buff->str)
			return (1);
		buff->str[0] = new_char;
		buff->size = 256;
		buff->capacity = 1;
	}
	else if ((buff->capacity + 1) < buff->size)
	{
		buff->str[buff->capacity] = new_char;
		buff->capacity++;
	}
	else
	{
		temp = NULL;
		extra_malloc(buff, temp, new_char);
	}
	return (0);
}
