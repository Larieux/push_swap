/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:14 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_change(t_struct *str, t_list *cur, t_list *cur_b)
{
	if (cur->content > cur_b->content && cur_b->content > (str->lower)->content)
	{
		str->lower = cur_b;
		str->tmp_best = str->lower;
		return (true);
	}
	return (false);
}

int	ft_tests_high_low(t_struct *str, t_list *cur, int *tmp_cost)
{
	*tmp_cost = ft_test_highest(str, cur, str->b);
	if (*tmp_cost != 0)
	{
		str->ft_cost = *tmp_cost;
		return (1);
	}
	ft_higher(str, str->b);
	*tmp_cost = ft_if_higher(str, cur, str->b);
	if (*tmp_cost != 0)
	{
		str->ft_cost = *tmp_cost;
		return (1);
	}
	ft_lower(str, str->b);
	*tmp_cost = ft_if_lower(str, cur, str->b);
	if (*tmp_cost != 0)
	{
		str->ft_cost = *tmp_cost;
		return (1);
	}
	return (0);
}

void	ft_cost_b(t_struct *str, t_list *cur)
{
	t_list	*cur_b;
	int		tmp_cost;

	if (ft_tests_high_low(str, cur, &tmp_cost) == 1)
		return ;
	tmp_cost = 1;
	cur_b = str->b;
	ft_set_cost_stuff(str, tmp_cost);
	while (cur_b != NULL && tmp_cost < str->med_b_row)
	{
		if (ft_change(str, cur, cur_b) == true)
			str->ft_cost = tmp_cost;
		tmp_cost++;
		cur_b = cur_b->next;
	}
	while (cur_b != NULL)
	{
		if (ft_change(str, cur, cur_b) == true)
		{
			str->ft_cost = tmp_cost;
			str->tmp_pos_med_b = true;
		}
		tmp_cost--;
		cur_b = cur_b->next;
	}
}

int	ft_cost_and_pos(t_struct *str)
{
	if ((str->tmp_pos_med_a == false && str->tmp_pos_med_b == false)
		|| (str->tmp_pos_med_a == true && str->tmp_pos_med_b == true))
	{
		if (str->ft_cost > str->pos)
			return (str->ft_cost);
		else
			return (str->pos);
	}
	else
		return (str->ft_cost + str->pos);
}

void	ft_best_cost(t_struct *str)
{
	t_list	*current;

	current = str->a;
	str->pos = 0;
	str->best = current;
	while (current != NULL)
	{
		str->tmp_pos_med_b = false;
		ft_cost_b(str, current);
		if (ft_cost_and_pos(str) < str->tot_cost)
			ft_set_best(str, current);
		if (str->pos < str->med_a_row && str->tmp_pos_med_a == false)
		{
			str->pos++;
			if (str->pos >= str->med_a_row)
			{
				str->pos--;
				str->tmp_pos_med_a = true;
			}
		}
		else if (str->tmp_pos_med_a == true)
			str->pos--;
		current = current->next;
	}
}
