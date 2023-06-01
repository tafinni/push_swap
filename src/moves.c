/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:39 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:41 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_heads	lowest_to_up(t_heads head, int original_len, int rot, int rev)
{
	t_stack	*temp;

	head = find_values(head);
	temp = head.b;
	while (temp->value != head.b_highest)
	{
		temp = temp->next;
		rot++;
	}
	rev = head.b_listlen - rot;
	if (rot <= rev)
	{
		while (head.b->value != head.b_highest)
			head.b = rotate(head.b, 2);
	}
	else
	{
		while (head.b->value != head.b_highest)
			head.b = reverse_rotate(head.b, 2);
	}
	while (list_lenght(head.a) < original_len)
		head = push_to_a(head);
	if (check_order(head.a) == -1)
		head.a = sort(head);
	return (head);
}

t_heads	rotate_both(t_heads head)
{
	head.a = rotate(head.a, 3);
	head.b = rotate(head.b, 0);
	return (head);
}

t_heads	reverse_both(t_heads head)
{
	head.a = reverse_rotate(head.a, 3);
	head.b = reverse_rotate(head.b, 0);
	return (head);
}

t_heads	count_moves_together(t_heads head)
{
	if (head.a_rot == 0 && head.a_rev == 0 \
	&& head.b_rot == 0 && head.b_rev == 0)
		head = reset_rounds(head);
	else if (head.a_rot == 0 && head.b_rot == 0)
		head = reset_rounds(head);
	else if (head.a_rot == 0 && head.b_rev == 0)
		head = reset_rounds(head);
	else if (head.a_rev == 0 && head.b_rot == 0)
		head = reset_rounds(head);
	else if (head.a_rev == 0 && head.b_rev == 0)
		head = reset_rounds(head);
	else if (head.a_rot <= head.a_rev && head.b_rot <= head.b_rev)
		head = move_counter(head, 1);
	else if (head.a_rev <= head.a_rot && head.b_rev <= head.b_rot)
		head = move_counter(head, 2);
	else if (head.a_rot <= head.a_rev && head.b_rev <= head.b_rot)
		head = move_counter_two(head, 3);
	else if (head.a_rev <= head.a_rot && head.b_rot <= head.b_rev)
		head = move_counter_two(head, 4);
	return (head);
}
