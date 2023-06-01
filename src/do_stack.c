/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:05 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:54:07 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*add_node_to_back(t_stack *stack, t_stack *new)
{
	t_stack	*last;
	t_stack	*previous;

	if (!stack)
	{
		stack = new;
		stack->next = NULL;
		stack->previous = NULL;
	}
	else
	{
		last = stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		previous = last;
		last = last->next;
		last->next = NULL;
		last->previous = previous;
	}
	return (stack);
}

static t_stack	*new_number_from_str(int number)
{
	t_stack	*result;

	result = NULL;
	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->value = number;
	result->next = NULL;
	return (result);
}

static void	do_duplicate(t_stack **a_stack, t_stack **temp)
{
	*temp = new_number_from_str(1);
	*a_stack = add_node_to_back(*a_stack, *temp);
	*temp = new_number_from_str(1);
	*a_stack = add_node_to_back(*a_stack, *temp);
}

t_stack	*input_to_stack(char **argv, t_stack *a_stack, int sign)
{
	int			i;
	long int	check;
	t_stack		*temp;

	if (sign == 1)
		i = 1;
	else
		i = 0;
	temp = a_stack;
	while (argv[i])
	{
		check = ft_atol(argv[i]);
		if (check > (long int)2147483647 || check < (long int)-2147483648)
			do_duplicate(&a_stack, &temp);
		else
		{
			temp = new_number_from_str(ft_atoi(argv[i]));
			a_stack = add_node_to_back(a_stack, temp);
		}
		i++;
	}
	return (a_stack);
}

t_stack	*free_stack(t_stack *start)
{
	t_stack	*temp;

	while (start != NULL)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
	return (start);
}
