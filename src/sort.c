/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:05 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:55:07 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_heads	count_moves_stacks(t_heads head, t_stack *check, int position)
{
	head.a_rot = 0;
	head.a_rev = 0;
	head = a_rot_rev_moves(head, position);
	head = b_rot_rev_moves(head, check);
	head.b_rot = head.position;
	head.b_rev = head.b_listlen - head.position;
	head = count_moves_together(head);
	return (head);
}

static t_heads	scroll_top_temp_null(t_heads head)
{
	head = check_if_high_value(head);
	head = count_moves_stacks(head, head.temp, head.position_to_top);
	if (head.moves <= head.count_to_top)
	{	
		if ((head.moves == head.count_to_top && head.compare_to->value \
		< head.temp->value) || (head.moves < head.count_to_top))
		{
			head.compare_to = head.temp;
			head = best_values(head, head.temp);
			head.best_move_sign = head.sign;
			head.count_to_top = head.moves;
		}
	}
	head.position_to_top++;
	return (head);
}

static t_heads	get_right_to_top(t_heads head)
{
	head = reset_values(head);
	head.temp = head.a;
	head = check_if_high_value(head);
	head = count_moves_stacks(head, head.temp, head.position_to_top);
	head.position_to_top++;
	head.compare_to = head.temp;
	head.count_to_top = head.moves;
	head = best_values(head, head.temp);
	head.best_move_sign = head.sign;
	head.temp = head.temp->next;
	while (head.temp != NULL)
	{
		head = scroll_top_temp_null(head);
		head.temp = head.temp->next;
	}
	head.sign = head.best_move_sign;
	if (head.sign > 0)
		head = do_operations(head);
	return (head);
}

static t_heads	sort_high(t_heads head)
{
	head = find_values(head);
	while (list_lenght(head.b) < 3 && list_lenght(head.a) > 3)
	{
		if (head.a->value != head.a_highest && head.a->value != \
		head.a_second_highest && head.a->value != head.a_third_highest \
		&& list_lenght(head.b) < 3)
			head = push_to_b(head);
		else
			head.a = rotate(head.a, 1);
		if (list_lenght(head.a) == 3)
			break ;
	}
	if (list_lenght(head.b) > 1)
		head.b = arrange_few_b(head, list_lenght(head.b));
	head = find_values(head);
	while (head.a_listlen > 3)
	{
		head = get_right_to_top(head);
		if (head.a->value != head.a_highest && head.a->value != \
		head.a_second_highest && head.a->value != head.a_third_highest)
			head = push_to_b(head);
		head = find_values(head);
	}
	head.a = arrange_three(head.a);
	return (head);
}

t_stack	*sort(t_heads head)
{
	int	original_lenght;

	original_lenght = list_lenght(head.a);
	if (original_lenght < 4)
	{
		head.a = arrange_few_a(head, original_lenght);
		return (head.a);
	}
	else
	{
		head = sort_high(head);
		if (head.b_listlen == 1)
		{
			head = push_to_a(head);
			return (head.a);
		}
		head = lowest_to_up(head, original_lenght, 0, 0);
	}
	return (head.a);
}
