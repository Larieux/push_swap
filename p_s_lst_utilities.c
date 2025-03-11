/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_lst_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:03 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:04 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_prev(t_list *lst, t_list *current)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lst;
	while (tmp != current && tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	return (prev);
}

int	ft_check_if_in_order(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 1;
	while (tmp != NULL && tmp->next != NULL
		&& tmp->content < (tmp->next)->content)
	{
		count++;
		tmp = tmp->next;
	}
	if (tmp != NULL && tmp->next != NULL)
		return (count);
	return (ft_lstsize(lst));
}

t_list	*ft_lst_median(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp->next != NULL && i < ft_median(lst))
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int	ft_median(t_list *lst)
{
	if (ft_lstsize(lst) < 3)
		return (ft_lstsize(lst));
	if (ft_lstsize(lst) % 2 == 0)
		return ((ft_lstsize(lst) / 2) + 1);
	else
		return (((ft_lstsize(lst) + 1) / 2));
}

void	set_highest_lowest(t_struct *str, t_list *lst)
{
	str->highest = lst;
	str->lowest = lst;
	while (lst != NULL)
	{
		if (lst->content > (str->highest)->content)
			str->highest = lst;
		if (lst->content < (str->lowest)->content)
			str->lowest = lst;
		lst = lst->next;
	}
}
