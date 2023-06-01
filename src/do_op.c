/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:53:57 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:53:59 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_heads	sign_one(t_heads head)
{
	if (head.a_least_rounds <= head.b_least_rounds)
	{
		while (head.a->value != head.a_best_top)
			head = rotate_both(head);
		while (head.b->value != head.b_best_top)
			head.b = rotate(head.b, 2);
	}
	if (head.b_least_rounds < head.a_least_rounds)
	{
		while (head.b->value != head.b_best_top)
			head = rotate_both(head);
		while (head.a->value != head.a_best_top)
			head.a = rotate(head.a, 1);
	}
	return (head);
}

static t_heads	sign_two(t_heads head)
{
	if (head.a_least_rounds <= head.b_least_rounds)
	{
		while (head.a->value != head.a_best_top)
			head = reverse_both(head);
		while (head.b->value != head.b_best_top)
			head.b = reverse_rotate(head.b, 2);
	}
	if (head.b_least_rounds < head.a_least_rounds)
	{
		while (head.b->value != head.b_best_top)
			head = reverse_both(head);
		while (head.a->value != head.a_best_top)
			head.a = reverse_rotate(head.a, 1);
	}
	return (head);
}

static t_heads	sign_three(t_heads head)
{
	while (head.a->value != head.a_best_top)
		head.a = rotate(head.a, 1);
	while (head.b->value != head.b_best_top)
		head.b = reverse_rotate(head.b, 2);
	return (head);
}

static t_heads	sign_four(t_heads head)
{
	while (head.a->value != head.a_best_top)
		head.a = reverse_rotate(head.a, 1);
	while (head.b->value != head.b_best_top)
		head.b = rotate(head.b, 2);
	return (head);
}

t_heads	do_operations(t_heads head)
{
	if (head.sign == 1)
		head = sign_one(head);
	else if (head.sign == 2)
		head = sign_two(head);
	else if (head.sign == 3)
		head = sign_three(head);
	else if (head.sign == 4)
		head = sign_four(head);
	return (head);
}
