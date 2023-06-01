/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:16 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:55:17 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_heads	arrange_more_than_three(t_heads head)
{
	if (head.a_last == head.a_lowest)
		head.a = reverse_rotate(head.a, 1);
	else
	{
		while (head.a->value != head.a_lowest)
			head.a = rotate(head.a, 1);
	}
	head = push_to_b(head);
	return (head);
}

t_stack	*arrange_few_a(t_heads head, int lenght)
{
	int	flag;

	flag = check_order(head.a);
	head = find_values(head);
	if (lenght < 4)
	{
		if (lenght == 3 && flag != 1)
			head.a = arrange_three(head.a);
		if (lenght == 2 && flag != 1)
			head.a = rotate(head.a, 1);
	}
	while (list_lenght(head.a) > 3)
		head = arrange_more_than_three(head);
	if (list_lenght(head.b) == 2 && check_order_reverse(head.b) != 1)
		head.b = rotate(head.b, 2);
	head.a = arrange_three(head.a);
	if (list_lenght(head.b) == 2)
		head = push_to_a(head);
	head = push_to_a(head);
	return (head.a);
}

t_stack	*arrange_few_b(t_heads head, int lenght)
{
	if (lenght < 4)
	{
		if (lenght == 3 && check_order_reverse(head.b) != 1)
			head.b = arrange_three_b(head.b);
		if (lenght == 2 && check_order_reverse(head.b) != 1)
			head.b = rotate(head.b, 2);
	}
	return (head.b);
}
