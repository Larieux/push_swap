/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:23:18 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:23:19 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*res;

	res = malloc(nmemb * size);
	if (res != NULL)
		ft_bzero(res, nmemb * size);
	else
		return (NULL);
	return (res);
}
