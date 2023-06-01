/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:32 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:34 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_lowest(t_stack *start)
{
	t_stack	*temp;
	int		lowest;

	temp = start;
	lowest = temp->value;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (lowest > temp->value)
			lowest = temp->value;
	}
	return (lowest);
}

t_heads	best_values(t_heads head, t_stack *temp)
{
	head.a_best_top = temp->value;
	head.b_best_top = head.b_value_to_top;
	head.a_least_rounds = head.a_rounds;
	head.b_least_rounds = head.b_rounds;
	return (head);
}

t_heads	reset_values(t_heads head)
{
	head.a_least_rounds = 0;
	head.b_least_rounds = 0;
	head.moves = 0;
	head.sign = 0;
	head.position_to_top = 0;
	head.best_move_sign = 0;
	head.count_to_top = 0;
	return (head);
}

t_heads	reset_rounds(t_heads head)
{
	head.a_rounds = 0;
	head.b_rounds = 0;
	head.moves = 0;
	head.sign = 0;
	return (head);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
