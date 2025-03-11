/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_low_high_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:51 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:52 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_test_highest(t_struct *str, t_list *cur, t_list *cur_b)
{
	int	cost;

	cost = 1;
	if (cur->content > (str->highest)->content
		|| cur->content < (str->lowest)->content)
	{
		str->tmp_best = str->highest;
		while (cur_b != str->highest && cost < str->med_b_row)
		{
			cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->highest)
			return (cost);
		while (cur_b != str->highest)
		{
			str->tmp_pos_med_b = true;
			cost--;
			cur_b = cur_b->next;
		}
		return (cost);
	}
	return (0);
}

void	ft_higher(t_struct *str, t_list *cur)
{
	str->higher = str->lowest;
	while (cur != NULL)
	{
		if (cur->content > (str->higher)->content
			&& (str->higher)->content < (str->highest)->content
			&& cur->content < (str->highest)->content)
		{
			str->higher = cur;
		}
		cur = cur->next;
	}
}

int	ft_if_higher(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	int		tmp_cost;

	tmp_cost = 0;
	if (cur_a->content > (str->higher)->content
		&& cur_a->content < (str->highest)->content)
	{
		str->tmp_best = str->higher;
		while (cur_b != NULL && cur_b != str->higher
			&& tmp_cost < str->med_b_row)
		{
			tmp_cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->higher)
			return (tmp_cost);
		while (cur_b != NULL && cur_b != str->higher)
		{
			str->tmp_pos_med_b = true;
			tmp_cost--;
			cur_b = cur_b->next;
		}
		return (tmp_cost);
	}
	return (0);
}

void	ft_lower(t_struct *str, t_list *cur)
{
	str->lower = str->highest;
	while (cur != NULL)
	{
		if (cur->content < (str->lower)->content
			&& (str->lower)->content > (str->lowest)->content
			&& cur->content > (str->lowest)->content)
		{
			str->lower = cur;
		}
		cur = cur->next;
	}
}

int	ft_if_lower(t_struct *str, t_list *cur_a, t_list *cur_b)
{
	int		tmp_cost;

	tmp_cost = 0;
	if (cur_a->content < (str->lower)->content
		&& cur_a->content > (str->lowest)->content)
	{
		str->tmp_best = str->lowest;
		while (cur_b != NULL && cur_b != str->lowest
			&& tmp_cost < str->med_b_row)
		{
			tmp_cost++;
			cur_b = cur_b->next;
		}
		if (cur_b == str->lowest)
			return (tmp_cost);
		while (cur_b != NULL && cur_b != str->lowest)
		{
			str->tmp_pos_med_b = true;
			tmp_cost--;
			cur_b = cur_b->next;
		}
		return (tmp_cost);
	}
	return (0);
}
