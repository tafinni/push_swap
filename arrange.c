#include "push_swap.h"

t_stack *operations_for_three(t_stack *beginning, int top, int middle, int bottom)
{
	if (top > bottom && top > middle)
		beginning = rotate(beginning, 1);
	else if ((bottom < middle && bottom < top) || (top < middle && middle > bottom))
		beginning = reverse_rotate(beginning, 1);
	else if (top > middle && top < bottom)
		beginning = swap(beginning, 1);
	return (beginning);
}

t_stack	*arrange_three(t_stack *start)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	while (check_order(start) != 1)
	{
		temp = start->next;
		top = start->value;
		middle = temp->value;
		temp = temp->next;
		bottom = temp->value;
		start = operations_for_three(start, top, middle, bottom);
	}
	return (start);
}

t_stack	*arrange_four(t_heads head)
{
	t_stack	*second;
	t_stack	*last;
	int		lowest;

	lowest = find_lowest(head.a);
	second = head.a->next;
	last = last_node(head.a);
	if (lowest == second->value)
		head.a = rotate(head.a, 1);
	if (lowest == second->next->value)
	{
		head.a = rotate(head.a, 1);
		head.a = rotate(head.a, 1);
	}
	if (lowest == last->value)
		head.a = reverse_rotate(head.a, 1);
	if (check_order(head.a) != 1)
	{
		head = push_to_b(head);
		head.a = arrange_three(head.a);
		head = push_to_a(head);
	}
	return (head.a);
}

t_heads	find_values(t_heads head, int sign)
{
	if (sign == 1)
	{
		head.listlen = list_lenght(head.a);
		if (head.listlen > 2)
			head.mid_value = middle_value(head.a);
		if (head.listlen > 1)
			head.last = (last_node(head.a))->value;
		if (head.listlen > 1)
			head.second = head.a->next->value;
	}
	if (sign == 2)
	{
		head.listlen = list_lenght(head.b);
		if (head.listlen > 2)
			head.mid_value = middle_value(head.b);
		if (head.listlen > 1)
			head.last = (last_node(head.b))->value;
		if (head.listlen > 1)
			head.second = head.a->next->value;
	}
	return (head);
}

int	is_under_mid_value(t_stack *start, t_heads head)
{
	t_stack	*temp;

	temp = start;
	while (temp != NULL)
	{
		if (temp->value <= head.mid_value)
			return (1);
		temp = temp->next;
	}
	return (-1);
}

int	rotate_or_reverse_for_mid_value(t_stack *start, t_heads head)
{
	t_stack	*temp;

	head.rot = 0;
	head.rev = 1;

	temp = start;
	while (temp != NULL)
	{
		if (temp->value <= head.mid_value)
			break;
		temp = temp->next;
		head.rot++;
	}
	temp = last_node(start);
	while (temp != NULL)
	{
		if (temp->value <= head.mid_value)
			break;
		temp = temp->previous;
		head.rev++;
	}
	if (head.rot <= head.rev)
		return (1);
	if (head.rot > head.rev)
		return (-1);
	return (0);
}

t_heads	look_for_smaller_than_mid(t_heads head)
{
	if (head.second <= head.mid_value || head.last <= head.mid_value)
	{
		if (head.second < head.a->value && head.second < head.last)
		{
			if (list_lenght(head.a) > 2)
				head.a = rotate(head.a, 1);
			else
				head.a = swap(head.a, 1);
		}
		head = find_values(head, 1);
		if (head.last < head.a->value && head.last < head.second)
			head.a = reverse_rotate(head.a, 1);
	}
	return (head);
}

t_heads	move_smaller_than_mid_from_far(t_heads head)
{
	if (rotate_or_reverse_for_mid_value(head.a, head) == 1)
	{
		while (head.a->value > head.mid_value)
			head.a = rotate(head.a, 1);
	}
	else
	{
		while (head.a->value > head.mid_value)
			head.a = reverse_rotate(head.a, 1);
	}
	return (head);
}

t_heads	move_lowest_to_top_a(t_heads head)
{
	t_stack	*temp;
	int		lowest;

	head.rot = 0;
	head.rev = 1;
	lowest = find_lowest(head.a);
	temp = head.a;
	while (temp != NULL)
	{
		if (temp->value == lowest)
			break;
		temp = temp->next;
		head.rot++;
	}
	temp = last_node(head.a);
	while (temp != NULL)
	{
		if (temp->value == lowest)
			break;
		temp = temp->previous;
		head.rev++;
	}
	if (head.rot <= head.rev)
	{
		while (head.a->value != lowest)
			head.a = rotate(head.a, 1);
	}
	else
	{
		while (head.a->value != lowest)
			head.a = reverse_rotate(head.a, 1);
	}
	return (head);
}

t_heads	while_a_more_than_three(t_heads head)
{
	while (list_lenght(head.a) > 3)
	{
		head = find_values(head, 1);
		if (is_under_mid_value(head.a, head) == 1)
			head = look_for_smaller_than_mid(head);
		else if (head.a->value > head.mid_value && is_under_mid_value(head.a, head) == 1)
			head = move_smaller_than_mid_from_far(head);
		else if (is_under_mid_value(head.a, head) != 1)
			head = move_lowest_to_top_a(head);
		head = push_to_b(head);
		if (check_order(head.a) == 1)
			break;
	}
	return (head);
}

t_stack	*move_highest_to_top_b(t_heads head)
{
	t_stack	*temp;
	int		highest;

	if (head.b != NULL)
	{
		head = find_values(head, 2);
		highest = find_highest(head.b);

		head.rot = 0;
		head.rev = 1;
		temp = head.b;
		while (temp != NULL)
		{
			if (temp->value == highest)
				break;
			temp = temp->next;
			head.rot++;
		}
		temp = last_node(head.b);
		while (temp != NULL)
		{
			if (temp->value == highest)
				break;
			temp = temp->previous;
			head.rev++;
		}
		if (head.rot <= head.rev)
		{
			while (head.b->value != highest)
				head.b = rotate(head.b, 2);
		}
		else
		{
			while (head.b->value != highest)
				head.b = reverse_rotate(head.b, 2);
		}
	}
	return (head.b);
}

t_stack	*pushed_node_too_high_a(t_heads head)
{
	t_stack	*temp;
	int		too_high;
	int		lowest;

	lowest = find_lowest(head.a);
	too_high = head.a->value;
	head = find_values(head, 1);
	head.rot = 0;
	head.rev = 0;
	temp = head.a->next;
	while (temp != NULL)
	{
		if (too_high < temp->value)
			break;
		temp = temp->next;
		head.rot++;
	}
	temp = last_node(head.a);
	while (temp != NULL)
	{
		if (too_high > temp->value)
			break;
		temp = temp->previous;
		head.rev++;
	}
	temp = head.a;
	if (head.rot <= head.rev)
	{
		while (head.a->value > head.a->next->value)
		{			
			head.a = swap(head.a, 1);
			head.a = rotate(head.a, 1);
		}
		while (head.a->value != lowest)
			head.a = reverse_rotate(head.a, 1);
	}
	else
	{	
		temp = last_node(head.a);
		while (head.rev > 0)
		{
			head.a = reverse_rotate(head.a, 1);
			head.a = swap(head.a, 1);
			head.rev--;
		}
		while (check_order(head.a) != 1)
			head.a = rotate(head.a, 1);
	}
	return (head.a);
}

t_stack	*arrange(t_heads head)
{
	int	original_lenght;

	head = find_values(head, 1);
	original_lenght = head.listlen;
	head.b = NULL;
	while (check_order(head.a) != 1 || original_lenght < list_lenght(head.a))
	{
		head = while_a_more_than_three(head);
		head.a = arrange_three(head.a);
	}
	while ((check_order(head.a) == 1 && head.b != NULL) || check_order(head.a) != 1)
	{
		head.b = move_highest_to_top_b(head);
		head = push_to_a(head);
		if (check_order(head.a) != 1)
			head.a = pushed_node_too_high_a(head);
	}
	return (head.a);
}
