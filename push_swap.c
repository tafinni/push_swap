#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack *temporary = head;

	while (temporary != NULL)
	{
		printf("%d\n", temporary->value);
		temporary = temporary->next;
	}
}

int	check_order(t_stack *beginning)
{
	t_stack	*jumper;
	int		endsign;
	int		current_value;
	int		next_value;

	jumper = beginning;
	endsign = 0;
	while (endsign == 0 && jumper != NULL)
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

t_stack *insert_to_head(t_stack *head, t_stack *current)
{
	current->next = head;
	return (current);
}

t_stack *new_number_from_str(char *s)
{
	int	number;
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	number = ft_atoi(s);
	result->value = number;
	result->next = NULL;
	result->previous = NULL;
	return (result);
}

t_stack	*input_to_stack(char **argv, t_stack *beginning)
{
	t_stack *old;
	t_stack	*new;
	int	i;

	i = 1;
	while (argv[i])
	{
		new = new_number_from_str(argv[i]);
		if (i == 1)
		{
			beginning = insert_to_head(beginning, new);
			old = beginning;
		}
		else
		{
			old->next = new;
			new->previous = old;
			old = new;
		}
		i++;
	}
	return (beginning);
}

int	main(int argc, char **argv)
{
	t_stack	*beginning;

	beginning = NULL;
	beginning = input_to_stack(argv, beginning);
	if (check_order(beginning) == 1)
	{
		printlist(beginning);
		printf("OK\n");
	}
	else
	{
		printlist(beginning);
		printf("NOT OK\n");
	}
	return (argc);
}