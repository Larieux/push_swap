/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:29:59 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:29:59 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_struct *str)
{
	if (ft_lstsize(str->a) > 3)
		ft_lst_push(str, &(str)->a, &(str)->b, 'b');
	if (ft_lstsize(str->a) > 3)
		ft_lst_push(str, &(str)->a, &(str)->b, 'b');
	if (str->b && (str->b)->next
		&& (str->b)->content < ((str->b)->next)->content)
		ft_lst_swap (&(str)->b, 'b');
	while (ft_lstsize(str->a) > 3)
	{
		ft_set_stuff(str);
		ft_best_cost(str);
		ft_sort(str);
	}
	ft_sort_two_or_three(str);
	while (ft_lstsize(str->b) > 0)
	{
		str->pos_med_a = false;
		str->med_a_row = ft_median(str->a);
		set_highest_lowest(str, str->a);
		ft_which_a(str);
		ft_last_sort(str);
	}
	ft_last_check(str);
}
