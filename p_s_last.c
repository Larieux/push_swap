/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:45 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:45 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tests_high_low_last(t_struct *str)
{
	if (ft_test_highest_last(str, str->b, str->a) != 0)
		return (1);
	ft_higher(str, str->a);
	if (ft_if_higher_last(str, str->b, str->a) != 0)
		return (1);
	ft_lower(str, str->a);
	if (ft_if_lower_last(str, str->b, str->a) != 0)
		return (1);
	return (0);
}

bool	ft_last_change(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	if (cur_b->content < cur_a->content
		&& cur_a->content < (str->higher)->content)
	{
		str->higher = cur_a;
		str->tmp_best = str->higher;
		return (true);
	}
	return (false);
}

void	ft_which_a(t_struct *str)
{
	t_list	*cur_a;
	int		i;

	if (ft_tests_high_low_last(str) == 1)
		return ;
	i = 0;
	cur_a = str->a;
	str->higher = str->highest;
	str->best = str->highest;
	while (cur_a != NULL && i < str->med_a_row)
	{
		ft_last_change(str, cur_a, str->b);
		i++;
		cur_a = cur_a->next;
	}
	while (cur_a != NULL)
	{
		if (ft_last_change(str, cur_a, str->b) == true)
		{
			str->pos_med_a = true;
		}
		i--;
		cur_a = cur_a->next;
	}
}

void	ft_last_sort(t_struct *str)
{
	while (str->a != str->tmp_best && str->pos_med_a == false)
	{
		ft_lst_rot(str, &(str)->a, 'a');
	}
	while (str->a != str->tmp_best && str->pos_med_a == true)
	{
		ft_lst_rev_rot(str, &(str)->a, 'a');
	}
	ft_lst_push(str, &(str)->b, &(str)->a, 'a');
}

void	ft_last_check(t_struct *str)
{
	int		order;
	int		size;

	size = ft_lstsize(str->a);
	while (ft_check_if_in_order(str->a) < size)
	{
		order = ft_check_if_in_order(str->a);
		if (order < ft_median(str->a))
		{
			ft_lst_rot(str, &(str)->a, 'a');
		}
		else if (order < size && order >= ft_median(str->a))
		{
			ft_lst_rev_rot(str, &(str)->a, 'a');
		}
	}
}
