#include "push_swap.h"

t_stack *swap_a(t_stack *beginning)
{
	t_stack	*second;

	second = beginning->next;
	second->previous = NULL;
	beginning->previous = second;
	beginning->next = second->next;
	second->next = beginning;
	return (second);
}

t_stack *rotate_a(t_stack *beginning)
{
	t_stack	*second;
	t_stack	*last;

	last = beginning;
	second = beginning->next;
	while (last->next != NULL)
		last = last->next;
	beginning->previous = last;
	second->previous = NULL;
	last->next = beginning;
	beginning->next = NULL;
	return (second);
}

t_stack	*reverse_rotate_a(t_stack *beginning)
{
	t_stack	*second_last;
	t_stack *last;

	last = beginning;
	while (last->next != NULL)
		last = last->next;
	second_last = last->previous;
	last->next = beginning;
	last->previous = NULL;
	second_last->next = NULL;
	return (last);
}

t_stack *new_number_from_int(int number, int sign)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->value = number;
	if (sign == 0)
		result->next = NULL;
	result->previous = NULL;
	return (result);
}

t_stack *push_to_other_stack(t_stack *current, t_stack *destination)
{
	t_stack *temp;
	int		sign;

	temp = NULL;
	sign = 0;
	if (!destination)
		sign = 1;
	else
		temp = destination;
	destination = new_number_from_int(current->value, sign);
	if (temp)
		destination->next = temp;
	return (destination);
}

t_stack *remove_beginning(t_stack *beginning)
{
	if (!beginning->next)
		free(beginning);
	else
	{
		beginning = beginning->next;
		beginning->previous = NULL;
	}
	return (beginning);
}