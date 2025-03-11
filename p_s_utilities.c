/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:35 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] == NULL)
		i++;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_set_stuff(t_struct *str)
{
	str->pos_med_a = false;
	str->tmp_pos_med_a = false;
	str->pos_med_b = false;
	str->tmp_pos_med_b = false;
	str->med_a_row = ft_median(str->a);
	str->med_b_row = ft_median(str->b);
	str->tot_cost = ft_lstsize(str->a) + ft_lstsize(str->b);
	set_highest_lowest(str, str->b);
}

void	ft_set_cost_stuff(t_struct *str, int tmp_cost)
{
	str->ft_cost = tmp_cost;
	str->lower = str->lowest;
	str->tmp_best = str->lowest;
}

void	ft_set_best(t_struct *str, t_list *current)
{
	if (str->tmp_pos_med_a == true)
		str->pos_med_a = true;
	else
		str->pos_med_a = false;
	if (str->tmp_pos_med_b == true)
		str->pos_med_b = true;
	else
		str->pos_med_b = false;
	str->tot_cost = ft_cost_and_pos(str);
	str->best = current;
	str->best_b = str->tmp_best;
}
