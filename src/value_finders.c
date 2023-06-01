/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:41 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:55:43 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_highest(t_stack *start)
{
	t_stack	*temp;
	int		highest;

	temp = start;
	highest = temp->value;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (highest < temp->value)
			highest = temp->value;
	}
	return (highest);
}

static int	find_second_highest(t_stack *start)
{
	t_stack	*temp;
	int		highest;
	int		not_this;

	temp = start;
	highest = temp->value;
	not_this = find_highest(start);
	if (temp->value == not_this)
	{
		temp = temp->next;
		highest = temp->value;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next != NULL)
		{
			if (temp->value == not_this)
				temp = temp->next;
		}
		if (highest < temp->value && temp->value != not_this)
			highest = temp->value;
	}
	return (highest);
}

static int	get_third(int highest, int second, int third, t_stack *temp)
{
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next != NULL)
		{	
			if (temp->value == highest || temp->value == second)
				temp = temp->next;
		}
		if (temp->value > third && temp->value != highest && \
			temp->value != second)
			third = temp->value;
	}
	return (third);
}

static int	find_third_highest(t_stack *start)
{
	t_stack	*temp;
	int		third;
	int		highest;
	int		second;

	temp = start;
	third = temp->value;
	highest = find_highest(start);
	second = find_second_highest(start);
	while (temp->value == highest || temp->value == second)
	{
		temp = temp->next;
		third = temp->value;
	}
	third = get_third(highest, second, third, temp);
	return (third);
}

t_heads	find_values(t_heads head)
{
	head.a_listlen = list_lenght(head.a);
	if (head.b != NULL)
		head.b_listlen = list_lenght(head.b);
	if (head.a_listlen > 1)
	{
		head.a_last = (last_node(head.a))->value;
		head.a_second = head.a->next->value;
		head.a_highest = find_highest(head.a);
		head.a_lowest = find_lowest(head.a);
		head.a_second_highest = find_second_highest(head.a);
		if (head.a_listlen > 3)
			head.a_third_highest = find_third_highest(head.a);
	}
	if (head.b != NULL && head.b_listlen > 1)
	{
		head.b_last = (last_node(head.b))->value;
		head.b_second = head.b->next->value;
	}
	if (head.b != NULL && head.b_listlen > 1)
	{
		head.b_lowest = find_lowest(head.b);
		head.b_highest = find_highest(head.b);
	}
	return (head);
}
