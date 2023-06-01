/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:34 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:55:36 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_heads	a_rot_rev_moves(t_heads head, int position)
{
	head.a_rot = position;
	head.a_rev = head.a_listlen - position;
	return (head);
}

static t_heads	value_lowest_or_highest(t_heads head, t_stack *to_check, int i)
{
	head.b_value_to_top = head.b_highest;
	if (to_check->value < head.b_lowest)
	{
		while (head.counter_temp->value != head.b_highest)
		{
			head.counter_temp = head.counter_temp->next;
			i++;
		}	
	}
	else if (to_check->value > head.b_highest)
	{
		while (head.counter_temp->value != head.b_highest)
		{
			head.counter_temp = head.counter_temp->next;
			i++;
		}
	}
	head.position = i;
	return (head);
}

static t_heads	set_values(t_heads head, int i)
{
	head.b_value_to_top = head.counter_temp->value;
	head.position = i;
	return (head);
}

static t_heads	not_lowhigh(t_heads head, t_stack *check, int last, int i)
{
	while (head.counter_temp != NULL)
	{
		if (check->value > head.counter_temp->value && \
		check->value < last)
		{
			head = set_values(head, i);
			break ;
		}
		else if (check->value > head.counter_temp->value && \
		check->value < last)
		{
			head = set_values(head, i);
			break ;
		}
		else if (check->value > head.counter_temp->value && \
		head.counter_temp->previous != NULL && \
		check->value < head.counter_temp->previous->value)
		{	
			head = set_values(head, i);
			break ;
		}
		head.counter_temp = head.counter_temp->next;
		i++;
	}
	return (head);
}

t_heads	b_rot_rev_moves(t_heads head, t_stack *to_check)
{
	int		last;
	int		i;

	i = 0;
	last = head.b_last;
	head.counter_temp = head.b;
	head.position = 0;
	if (to_check->value < head.b_lowest || to_check->value > head.b_highest)
		head = value_lowest_or_highest(head, to_check, i);
	else
		head = not_lowhigh(head, to_check, last, i);
	return (head);
}
