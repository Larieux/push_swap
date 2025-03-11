/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_init_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:39 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:39 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_a(t_struct *str, char **argv)
{
	int			i;
	int			num;
	t_list		*current;

	i = 1;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		current = ft_lstnew(num);
		ft_lstadd_back(&(str)->a, current);
		i++;
	}
}
