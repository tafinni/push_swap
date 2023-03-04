#include "push_swap.h"

t_stack *add_node_to_back(t_stack *stack, t_stack *new)
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

t_stack	*new_number_from_str(int number)
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

t_stack	*input_to_stack(char **argv, t_stack *a_stack)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = a_stack;
	while (argv[i])
	{
		temp = new_number_from_str(ft_atoi(argv[i]));
		a_stack = add_node_to_back(a_stack, temp);
		i++;
	}
	return (a_stack);
}

int	check_stdin(int argc, char **argv)
{
	int	i;
	int	y;
	if (argc < 2)
		return (-1);
	i = 1;
	y = 0;
	while (argv[i])
	{
		while (argv[i][y])
		{
			if (ft_isdigit(argv[i][y]) != 1)
				return (-1);
			else
				y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

t_stack	*sort(int argc, t_heads head)
{
	if (argc == 3)
	{
		if (head.a->value > head.a->next->value)
			head.a = swap(head.a, 1);
	}
	if (argc == 4)
		head.a = arrange_three(head.a);
	if (argc == 5)
		head.a = arrange_four(head);
	if (argc > 5)
		head.a = arrange(head);
	return (head.a);
}

int	main(int argc, char **argv)
{
	t_heads	head;

	if (check_stdin(argc, argv) == -1)
	{
		write(1, "STDIN: ERROR\n", 14);
		return (0);
	}
	else
	{
		head.a = NULL;
		head.b = NULL;
		head.a = input_to_stack(argv, head.a);
		if (check_order(head.a) == 1)
			return (0);
		else
			head.a = sort(argc, head);
	}
	return (argc);
}
