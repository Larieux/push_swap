/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:28:15 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:28:16 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenlittle;

	i = 0;
	lenlittle = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i + lenlittle <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == lenlittle)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
