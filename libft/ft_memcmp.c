/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:25:53 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:25:54 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cuc1;
	const unsigned char	*cuc2;

	cuc1 = (unsigned char *)s1;
	cuc2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cuc1[i] != cuc2[i])
		{
			return (cuc1[i] - cuc2[i]);
		}
		i++;
	}
	return (0);
}
