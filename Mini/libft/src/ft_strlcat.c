/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:03:38 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/14 18:33:21 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcat(char *dst, char src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	new_len;

	len_src = 1;
	len_dst = ft_strlen(dst);
	new_len = len_src + dstsize;
	if (dstsize > len_dst)
		new_len = len_src + len_dst;
	while ((len_dst + 1) < dstsize)
	{
		dst[len_dst] = src;
		len_dst++;
	}
	dst[len_dst] = '\0';
}
