/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:27:11 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:27:11 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_is_mult(char **dtab, char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;

	i = 0;
	count = 0;
	while (dtab[i] != NULL && str != NULL)
	{
		j = 0;
		k = 0;
		while (str[k] != '\0' && dtab[i][j] != '\0' && dtab[i][j] == str[k])
		{
			k++;
			j++;
		}
		if (k == ft_strlen(str) && k == ft_strlen(dtab[i]))
			count++;
		i++;
	}
	return (count);
}
