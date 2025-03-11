/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_sort_two_or_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:15 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:16 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_struct *str)
{
	if ((str->a)->content > ((str->a)->next)->content)
	{
		ft_lst_rot(str, &(str)->a, 'a');
	}
}

void	ft_sort_three(t_struct *str)
{
	if ((str->a)->content > ((str->a)->next)->content
		&& ((str->a)->next)->content > (((str->a)->next)->next)->content)
	{
		ft_lst_swap(&(str)->a, 'a');
	}
	else if ((str->a)->content > ((str->a)->next)->content
		&& ((str->a)->next)->content < (((str->a)->next)->next)->content
		&& (str->a)->content < (((str->a)->next)->next)->content)
	{
		ft_lst_swap(&(str)->a, 'a');
	}
	else if ((str->a)->content < ((str->a)->next)->content
		&& ((str->a)->next)->content > (((str->a)->next)->next)->content
		&& (str->a)->content < (((str->a)->next)->next)->content)
	{
		ft_lst_swap(&(str)->a, 'a');
	}
}

void	ft_sort_two_or_three(t_struct *str)
{
	if (ft_lstsize(str->a) == 2)
		ft_sort_two(str);
	else if (ft_lstsize(str->a) == 3)
		ft_sort_three(str);
}
