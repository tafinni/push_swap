#include "push_swap.h"

t_stack *swap(t_stack *start, int sign)
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
	if (sign == 1)
		printf("sa\n");
	if (sign == 2)
		printf("sb\n");
	if (sign == 3)
		printf("ss\n");
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
	if (sign == 1)
		printf("ra\n");
	if (sign == 2)
		printf("rb\n");
	if (sign == 3)
		printf("rr\n");
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
	if (sign == 1)
		printf("rra\n");
	if (sign == 2)
		printf("rrb\n");
	if (sign == 3)
		printf("rrr\n");
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
	printf("pb\n");
	return (head);
}

t_heads	push_to_a(t_heads head)
{
	t_stack *temp;

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
		printf("pa\n");
	}
	return (head);
}
