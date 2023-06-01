/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:24 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:55:25 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*op_for_three(t_stack *start, int top, int middle, int bottom)
{
	if (top > bottom && top > middle)
		start = rotate(start, 1);
	else if ((bottom < middle && bottom < top) || \
			(top < middle && middle > bottom))
		start = reverse_rotate(start, 1);
	else if (top > middle && top < bottom)
		start = swap(start, 1);
	return (start);
}

static t_stack	*op_for_three_b(t_stack *start, int top, int middle, int bottom)
{
	if (top < bottom && top < middle)
		start = rotate(start, 2);
	else if ((bottom > middle && bottom > top) || \
			(top > middle && middle < bottom))
		start = reverse_rotate(start, 2);
	else if (top < middle && top > bottom)
		start = swap(start, 2);
	return (start);
}

t_stack	*arrange_three(t_stack *start)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	while (check_order(start) != 1)
	{
		temp = start->next;
		top = start->value;
		middle = temp->value;
		temp = temp->next;
		bottom = temp->value;
		start = op_for_three(start, top, middle, bottom);
	}
	return (start);
}

t_stack	*arrange_three_b(t_stack *start)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	while (check_order_reverse(start) != 1)
	{
		temp = start->next;
		top = start->value;
		middle = temp->value;
		temp = temp->next;
		bottom = temp->value;
		start = op_for_three_b(start, top, middle, bottom);
	}
	return (start);
}
