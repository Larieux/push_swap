/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_errors_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:26 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:30:27 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_error_arg(char **split_arg, int j, int k)
{
	if (k == 0)
	{
		if (!(split_arg[j][k] >= '0' && split_arg[j][k] <= '9')
			&& split_arg[j][k] != '+' && split_arg[j][k] != '-')
		{
			free_dtab(split_arg);
			return (-1);
		}
		if ((split_arg[j][k] == '+' || split_arg[j][k] == '-')
			&& !(split_arg[j][k + 1] >= '0' && split_arg[j][k + 1] <= '9'))
		{
			free_dtab(split_arg);
			return (-1);
		}
	}
	else
	{
		if (!(split_arg[j][k] >= '0' && split_arg[j][k] <= '9'))
		{
			free_dtab(split_arg);
			return (-1);
		}
	}
	return (0);
}

int	ft_init_a(t_struct *str, char **arg)
{
	int			i;
	long		num;
	t_list		*current;

	i = 0;
	while (arg[i] != NULL)
	{
		num = ft_atoi(arg[i]);
		if (num < -2147483648 || num > 2147483647)
			return (-1);
		current = ft_lstnew(num);
		ft_lstadd_back(&(str)->a, current);
		i++;
	}
	return (0);
}

int	ft_find_error_args(t_struct *str, char **argv, int i)
{
	int		j;
	int		k;
	char	**split_arg;

	j = 0;
	split_arg = ft_split(argv[i], ' ');
	while (split_arg[j] != NULL)
	{
		k = 0;
		while (split_arg[j][k] != '\0')
		{
			if (ft_find_error_arg(split_arg, j, k) == -1)
				return (-1);
			k++;
		}
		j++;
	}
	if (ft_init_a(str, split_arg) == -1)
	{
		free_dtab(split_arg);
		return (-1);
	}
	free_dtab(split_arg);
	return (0);
}

size_t	ft_str_have_mult_int(t_list *list)
{
	size_t	count;
	t_list	*current;
	t_list	*sec_current;

	count = 0;
	current = list;
	while (current != NULL)
	{
		sec_current = current->next;
		while (sec_current != NULL)
		{
			if (current->content == sec_current->content)
				count++;
			sec_current = sec_current->next;
		}
		current = current->next;
	}
	return (count);
}

int	ft_args_errors_init(t_struct *str, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_find_error_args(str, argv, i) == -1)
			return (-1);
		i++;
	}
	if (ft_str_have_mult_int(str->a) > 0)
		return (-1);
	return (i);
}
