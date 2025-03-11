/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:22 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:22 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bef_med(t_struct *str)
{
	if (str->pos_med_b == false)
	{
		if (str->b != str->best_b && str->a != str->best)
			ft_lst_rot_two(str);
		else if (str->b == str->best_b && str->a != str->best)
			ft_lst_rot(str, &(str->a), 'a');
		else if (str->b != str->best_b && str->a == str->best)
			ft_lst_rot(str, &(str->b), 'b');
	}
	else if (str->pos_med_b == true)
	{
		if (str->b != str->best_b && str->a != str->best)
		{
			ft_lst_rot(str, &(str->a), 'a');
			ft_lst_rev_rot(str, &(str->b), 'b');
		}
		else if (str->b == str->best_b && str->a != str->best)
			ft_lst_rot(str, &(str->a), 'a');
		else if (str->b != str->best_b && str->a == str->best)
			ft_lst_rev_rot(str, &(str->b), 'b');
	}
}

void	ft_sort_aft_med(t_struct *str)
{
	if (str->pos_med_b == false)
	{
		if (str->b != str->best_b && str->a != str->best)
		{
			ft_lst_rev_rot(str, &(str->a), 'a');
			ft_lst_rot(str, &(str->b), 'b');
		}
		else if (str->b == str->best_b && str->a != str->best)
			ft_lst_rev_rot(str, &(str->a), 'a');
		else if (str->b != str->best_b && str->a == str->best)
			ft_lst_rot(str, &(str->b), 'b');
	}
	else if (str->pos_med_b == true)
	{
		if (str->b != str->best_b && str->a != str->best)
			ft_lst_rev_rot_two(str);
		else if (str->b == str->best_b && str->a != str->best)
			ft_lst_rev_rot(str, &(str->a), 'a');
		else if (str->b != str->best_b && str->a == str->best)
			ft_lst_rev_rot(str, &(str->b), 'b');
	}
}

void	ft_sort(t_struct *str)
{
	while ((str->a != NULL && str->b != NULL)
		&& (str->a != str->best || str->b != str->best_b))
	{
		if (str->pos_med_a == false)
			ft_sort_bef_med(str);
		else
			ft_sort_aft_med(str);
	}
	if (str->a != NULL && str->b != NULL
		&& str->a == str->best && str->b == str->best_b)
		ft_lst_push(str, &(str)->a, &(str)->b, 'b');
}
