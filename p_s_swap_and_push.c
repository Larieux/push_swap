/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_swap_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:28 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:29 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_swap(t_list **lst, char role)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	else if (ft_lstsize (*lst) > 1)
	{
		tmp = (*lst)->next;
		(*lst)->next = ((*lst)->next)->next;
		if ((*lst)->next != NULL && ((*lst)->next)->next != NULL)
			(*lst)->next = *lst;
		tmp->next = *lst;
		*lst = tmp;
		if (role == 'a')
			write (1, "sa\n", 3);
		else if (role == 'b')
			write (1, "sb\n", 3);
	}
}

void	ft_lst_swap_two(t_struct *str)
{
	ft_lst_swap(&(str)->a, 'c');
	ft_lst_swap(&(str)->b, 'c');
	write (1, "ss\n", 3);
}

void	ft_lst_push(t_struct *str, t_list **a, t_list **b, char role)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	if (str->highest != NULL && (*b)->content > (str->highest)->content)
		str->highest = *b;
	else if (str->highest == NULL)
		str->highest = *b;
	if (str->lowest != NULL && (*b)->content < (str->lowest)->content)
		str->lowest = *b;
	else if (str->lowest == NULL)
		str->lowest = *b;
	if (role == 'a')
		write (1, "pa\n", 3);
	else if (role == 'b')
		write (1, "pb\n", 3);
}
