/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_low_high_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:58 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:58 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_test_highest_last(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	int		tmp_cost;

	tmp_cost = 0;
	if (cur_a->content > (str->highest)->content
		|| cur_a->content < (str->lowest)->content)
	{
		str->tmp_best = str->lowest;
		while (cur_b != str->lowest && tmp_cost < str->med_a_row)
		{
			tmp_cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->lowest)
			return (tmp_cost);
		while (cur_b != str->lowest)
		{
			str->pos_med_a = true;
			tmp_cost--;
			cur_b = cur_b->next;
		}
		return (tmp_cost);
	}
	return (0);
}

int	ft_if_higher_last(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	int		tmp_cost;

	tmp_cost = 0;
	if (cur_a->content > (str->higher)->content
		&& cur_a->content < (str->highest)->content)
	{
		str->tmp_best = str->highest;
		while (cur_b != NULL && cur_b != str->highest
			&& tmp_cost < str->med_a_row)
		{
			tmp_cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->highest)
			return (tmp_cost);
		while (cur_b != NULL && cur_b != str->highest)
		{
			str->pos_med_a = true;
			tmp_cost--;
			cur_b = cur_b->next;
		}
		return (tmp_cost);
	}
	return (0);
}

int	ft_if_lower_last(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	int		tmp_cost;

	tmp_cost = 0;
	if (cur_a->content < (str->lower)->content
		&& cur_a->content > (str->lowest)->content)
	{
		str->tmp_best = str->lower;
		while (cur_b != NULL && cur_b != str->lower
			&& tmp_cost < str->med_a_row)
		{
			tmp_cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->lower)
			return (tmp_cost);
		while (cur_b != NULL && cur_b != str->lower)
		{
			str->pos_med_a = true;
			tmp_cost--;
			cur_b = cur_b->next;
		}
		return (tmp_cost);
	}
	return (0);
}
