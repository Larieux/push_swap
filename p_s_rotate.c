/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:09 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:10 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_rot(t_struct *str, t_list **lst, char role)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	else if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_lstadd_back(lst, tmp);
		if (role == 'a')
		{
			str->a = *lst;
			write (1, "ra\n", 3);
		}
		else if (role == 'b')
		{
			str->b = *lst;
			write (1, "rb\n", 3);
		}
	}
}

void	ft_lst_rot_two(t_struct *str)
{
	ft_lst_rot(str, &(str)->a, 'c');
	ft_lst_rot(str, &(str)->b, 'c');
	write (1, "rr\n", 3);
}

void	ft_lst_rev_rot(t_struct *str, t_list **lst, char role)
{
	t_list	*tmp;
	t_list	*prev;

	if (*lst == NULL)
		return ;
	else if (ft_lstsize(*lst) > 1)
	{
		tmp = ft_lstlast(*lst);
		prev = ft_lst_prev(*lst, tmp);
		prev->next = NULL;
		ft_lstadd_front(lst, tmp);
		if (role == 'a')
		{
			str->a = *lst;
			write (1, "rra\n", 4);
		}
		else if (role == 'b')
		{
			str->b = *lst;
			write (1, "rrb\n", 4);
		}
	}
}

void	ft_lst_rev_rot_two(t_struct *str)
{
	ft_lst_rev_rot(str, &(str)->a, 'c');
	ft_lst_rev_rot(str, &(str)->b, 'c');
	write (1, "rrr\n", 4);
}
