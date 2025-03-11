/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:42 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	str;
	int			size;

	str.a = NULL;
	str.b = NULL;
	str.highest = NULL;
	str.lowest = NULL;
	if (argc < 1 || ft_args_errors_init(&str, argv) == -1)
	{
		ft_lstclear(&(str.a));
		return (write(2, "Error\n", 6), 0);
	}
	size = ft_lstsize(str.a);
	if (ft_check_if_in_order(str.a) == size)
		return (ft_lstclear(&(str.a)), 0);
	if (size > 1 && size < 4)
	{
		ft_sort_two_or_three(&str);
		ft_last_check(&str);
	}
	if (ft_lstsize(str.a) > 3)
		ft_algorithm(&str);
	ft_lstclear(&(str.a));
	ft_lstclear(&(str.b));
	return (0);
}
