#include "push_swap.h"

int	check_order(t_stack *start)
{
	t_stack	*jumper;
	int		current_value;
	int		next_value;

	jumper = start;
	while(jumper != NULL)
	{
		current_value = jumper->value;
		jumper = jumper->next;
		if (jumper != NULL)
			next_value = jumper->value;
		if (!next_value)
			break;
		if (current_value > next_value)
			return (-1);
	}
	return (1);
}

int	list_lenght(t_stack *start)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = start;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

t_stack	*last_node(t_stack *start)
{
	t_stack	*temp;

	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	find_highest(t_stack *start)
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

int	search_for_middle_value(t_stack *start, int count, int value)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i < count)
	{
		temp = start;
		while (temp != NULL)
		{
			if (value == temp->value)
			{
				i++;
				temp = temp->next;
				break;
			}
			temp = temp->next;
		}
		value++;
	}
	return (value - 1);
}

int middle_value(t_stack *start)
{
	int		count;
	int		value;

	count = list_lenght(start) / 2;
	value = find_lowest(start);
	value = search_for_middle_value(start, count, value);
	return (value);
}
