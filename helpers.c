#include "push_swap.h"

int	find_lowest(t_stack *beginning)
{
	t_stack	*temp;
	int	lowest;

	temp = beginning;
	lowest = temp->value;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (lowest > temp->value)
			lowest = temp->value;	
	}
	return (lowest);
}

int	find_highest(t_stack *beginning)
{
	t_stack	*temp;
	int		highest;

	temp = beginning;
	highest = temp->value;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (highest < temp->value)
			highest = temp->value;
	}
	return (highest);
}

t_stack *go_to_last(t_stack *beginning)
{
	t_stack	*temp;

	temp = beginning;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	list_lenght(t_stack *beginning)
{
	t_stack *temp;
	int		i;

	i = 0;
	temp = beginning;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}