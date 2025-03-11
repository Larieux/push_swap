/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:48 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:59 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_struct
{
	t_list	*a;
	t_list	*b;
	t_list	*best;
	t_list	*best_b;
	t_list	*tmp_best;
	t_list	*med_a;
	t_list	*med_b;
	t_list	*highest;
	t_list	*higher;
	t_list	*lowest;
	t_list	*lower;
	int		tot_cost;
	int		ft_cost;
	int		pos;
	int		med_a_row;
	int		med_b_row;
	bool	tmp_pos_med_a;
	bool	pos_med_a;
	bool	pos_med_b;
	bool	tmp_pos_med_b;

}					t_struct;

/* ************************************************************************** */
/* 																			  */
/* 									operations								  */
/* 																			  */
/* ************************************************************************** */

/**
 * @brief role "a" for sa or "b" for sb
 * 
 * @param lst 
 */
void	ft_lst_swap(t_list **lst, char role);

void	ft_lst_swap_two(t_struct *lists);

/**
 * @brief role "a" for ra or "b" for rb.
 * Shift up all elements of stack by 1.
 * The first element becomes the last one.
 * 
 * @param str 
 * @param lst 
 * @param role 
 */
void	ft_lst_rot(t_struct *str, t_list **lst, char role);

/**
 * @brief role "a" for ra or "b" for rb.
 * Shift up all elements of stack by 1.
 * The first element becomes the last one.
 * 
 * @param a 
 * @param b 
 */
void	ft_lst_rot_two(t_struct *str);

/**
 * @brief role "a" for rra or "b" for rrb.
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param str 
 * @param lst 
 * @param role 
 */
void	ft_lst_rev_rot(t_struct *str, t_list **lst, char role);

/**
 * @brief role "a" for rra or "b" for rrb.
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param lists 
 */
void	ft_lst_rev_rot_two(t_struct *lists);

/**
 * @brief role "a" for pa = push from a or "b" for pb = push from b
 * 
 * @param str 
 * @param a 
 * @param b 
 * @param role 
 */
void	ft_lst_push(t_struct *str, t_list **a, t_list **b, char role);

/* ************************************************************************** */
/* 																			  */
/* 								lst_utilities								  */
/* 																			  */
/* ************************************************************************** */

t_list	*ft_lst_prev(t_list *lst, t_list *current);

int		ft_check_if_in_order(t_list *lst);

t_list	*ft_lst_median(t_list *lst);

int		ft_median(t_list *lst);

/**
 * @brief Set the highest lowest object
 * 
 * @param str 
 * @param lst 
 */
void	set_highest_lowest(t_struct *str, t_list *lst);

/* ************************************************************************** */
/* 																			  */
/* 									utilities								  */
/* 																			  */
/* ************************************************************************** */

void	free_dtab(char **tab);

void	ft_set_stuff(t_struct *str);

void	ft_set_cost_stuff(t_struct *str, int tmp_cost);

void	ft_set_best(t_struct *str, t_list *current);

/* ************************************************************************** */
/* 																			  */
/* 									errors_init								  */
/* 																			  */
/* ************************************************************************** */

int		ft_find_error_arg(char **split_arg, int j, int k);

int		ft_init_a(t_struct *str, char **arg);

int		ft_find_error_args(t_struct *str, char **argv, int i);

size_t	ft_str_have_mult_int(t_list *list);

int		ft_args_errors_init(t_struct *str, char **argv);

/* ************************************************************************** */
/* 																			  */
/* 								sort_two_or_three							  */
/* 																			  */
/* ************************************************************************** */

void	ft_sort_two(t_struct *str);

/**
 * @brief sorts when list == 3 numbers
 * 
 * @param a 
 */
void	ft_sort_three(t_struct *str);

/**
 * @brief checks and sorts if there are only two
 * or three numbers.
 * 
 * @param str 
 */
void	ft_sort_two_or_three(t_struct *str);

/* ************************************************************************** */
/* 																			  */
/* 									algorithm								  */
/* 																			  */
/* ************************************************************************** */

void	ft_algorithm(t_struct *str);

/* ************************************************************************** */
/* 																			  */
/* 									costs									  */
/* 																			  */
/* ************************************************************************** */

bool	ft_change(t_struct *str, t_list *cur, t_list *cur_b);

int		ft_tests_high_low(t_struct *str, t_list *cur, int *tmp_cost);

void	ft_cost_b(t_struct *str, t_list *cur);

int		ft_cost_and_pos(t_struct *str);

void	ft_best_cost(t_struct *str);

/* ************************************************************************** */
/* 																			  */
/* 								low_high_first								  */
/* 																			  */
/* ************************************************************************** */

int		ft_test_highest(t_struct *str, t_list *cur, t_list *cur_b);

void	ft_higher(t_struct *str, t_list *cur);

int		ft_if_higher(t_struct *str, t_list *cur_a, t_list *cur_b);

void	ft_lower(t_struct *str, t_list *cur);

int		ft_if_lower(t_struct *str, t_list *cur_a, t_list *cur_b);

/* ************************************************************************** */
/* 																			  */
/* 									sort									  */
/* 																			  */
/* ************************************************************************** */

void	ft_sort_bef_med(t_struct *str);

void	ft_sort_aft_med(t_struct *str);

void	ft_sort(t_struct *str);

/* ************************************************************************** */
/* 																			  */
/* 									last									  */
/* 																			  */
/* ************************************************************************** */

int		ft_tests_high_low_last(t_struct *str);

bool	ft_last_change(t_struct *str, t_list *cur_a, t_list *cur_b);

void	ft_which_a(t_struct *str);

void	ft_last_sort(t_struct *str);

/**
 * @brief checks if a is in order and puts it in order if not with ra or rra
 * 
 * @param str 
 */
void	ft_last_check(t_struct *str);

/* ************************************************************************** */
/* 																			  */
/* 								low_high_last								  */
/* 																			  */
/* ************************************************************************** */

int		ft_test_highest_last(t_struct *str, t_list *cur_a, t_list *cur_b);

int		ft_if_higher_last(t_struct *str, t_list *cur_a, t_list *cur_b);

int		ft_if_lower_last(t_struct *str, t_list *cur_a, t_list *cur_b);

#endif