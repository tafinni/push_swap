/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:51 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:54 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap(t_stack *start, int sign)
{
	t_stack	*second;
	t_stack	*third;

	second = start->next;
	third = second->next;
	second->next = start;
	second->previous = NULL;
	start->previous = second;
	start->next = third;
	third->previous = start;
	if (sign != 0)
	{
		if (sign == 1)
			write(1, "sa\n", 3);
		else if (sign == 2)
			write(1, "sb\n", 3);
		else if (sign == 3)
			write(1, "ss\n", 3);
	}
	return (second);
}

t_stack	*rotate(t_stack *start, int sign)
{
	t_stack	*second;
	t_stack	*last;

	last = last_node(start);
	second = start->next;
	start->previous = last;
	second->previous = NULL;
	last->next = start;
	start->next = NULL;
	if (sign != 0)
	{
		if (sign == 1)
			write(1, "ra\n", 3);
		else if (sign == 2)
			write(1, "rb\n", 3);
		else if (sign == 3)
			write(1, "rr\n", 3);
	}
	return (second);
}

t_stack	*reverse_rotate(t_stack *start, int sign)
{
	t_stack	*last;
	t_stack	*second_last;

	last = start;
	while (last->next != NULL)
		last = last->next;
	second_last = last->previous;
	second_last->next = NULL;
	last->previous = NULL;
	last->next = start;
	start->previous = last;
	start = start->previous;
	if (sign != 0)
	{
		if (sign == 1)
			write(1, "rra\n", 4);
		else if (sign == 2)
			write(1, "rrb\n", 4);
		else if (sign == 3)
			write(1, "rrr\n", 4);
	}
	return (start);
}

t_heads	push_to_b(t_heads head)
{
	t_stack	*temp;

	temp = head.a;
	head.a = head.a->next;
	if (head.b == NULL)
	{	
		head.b = temp;
		head.b->next = NULL;
	}
	else
	{
		temp->next = head.b;
		head.b->previous = temp;
		head.b = head.b->previous;
	}
	head.b->previous = NULL;
	head.a->previous = NULL;
	write(1, "pb\n", 3);
	return (head);
}

t_heads	push_to_a(t_heads head)
{
	t_stack	*temp;

	if (head.b != NULL)
	{
		temp = head.b;
		if (head.b->next != NULL)
		{
			head.b = head.b->next;
			head.b->previous = NULL;
		}
		else
			head.b = NULL;
		temp->next = head.a;
		head.a->previous = temp;
		head.a = head.a->previous;
		head.a->previous = NULL;
		write(1, "pa\n", 3);
	}
	return (head);
}
