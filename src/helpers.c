/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:26 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:28 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order(t_stack *start)
{
	t_stack	*jumper;
	int		current_value;
	int		next_value;

	jumper = start;
	while (jumper != NULL)
	{
		current_value = jumper->value;
		jumper = jumper->next;
		if (jumper != NULL)
			next_value = jumper->value;
		if (current_value > next_value)
			return (-1);
	}
	return (1);
}

int	check_order_reverse(t_stack *start)
{
	t_stack	*jumper;
	int		current_value;
	int		next_value;

	jumper = start;
	while (jumper != NULL)
	{
		current_value = jumper->value;
		jumper = jumper->next;
		if (jumper != NULL)
			next_value = jumper->value;
		if (!next_value)
			break ;
		if (current_value < next_value)
			return (-1);
	}
	return (1);
}

int	list_lenght(t_stack *start)
{
	int		count;
	t_stack	*temp;

	count = 0;
	if (start != NULL)
	{
		temp = start;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
	}
	return (count);
}

t_heads	check_if_high_value(t_heads head)
{
	while (head.temp->value == head.a_highest || head.temp->value \
	== head.a_second_highest || head.temp->value == head.a_third_highest)
	{	
		if (head.temp->next == NULL)
			break ;
		head.temp = head.temp->next;
		head.position_to_top++;
		head = find_values(head);
	}
	return (head);
}

t_stack	*last_node(t_stack *start)
{
	t_stack	*temp;

	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
