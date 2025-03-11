/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:25:23 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:25:23 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*newlist;
	t_list	*newelem;

	newlist = 0;
	while (lst)
	{
		newelem = ft_lstnew(0);
		if (newelem == 0)
		{
			ft_lstclear(&newlist);
			return (NULL);
		}
		newelem->content = f(lst->content);
		ft_lstadd_back(&newlist, newelem);
		lst = lst->next;
	}
	return (newlist);
}
