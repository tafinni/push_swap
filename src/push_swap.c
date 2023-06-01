/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:27:07 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 15:27:11 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicates(t_stack *list)
{
	t_stack	*move;
	t_stack	*start;
	int		counter;

	start = list;
	while (list != NULL)
	{
		move = start;
		counter = 0;
		while (move != NULL)
		{
			if (move->value == list->value)
				counter++;
			if (counter == 2)
				return (-1);
			move = move->next;
		}
		list = list->next;
	}
	return (0);
}

static int	check_stdin(int argc, char **argv, int sign, int y)
{
	int	i;

	i = 0;
	if (sign == 1)
		i = 1;
	while (argv[i])
	{
		while (argv[i][y])
		{
			if ((argv[i][y] == '-' && argv[i][y + 1]) \
			|| (argv[i][y] == '+' && argv[i][y + 1]))
				y++;
			if (ft_isdigit(argv[i][y]) != 1)
				return (-1);
			if (ft_atol(argv[i]) < (long int)-2147483648 \
			|| (ft_atol(argv[i]) > 2147483647))
				return (-1);
			else
				y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

static t_heads	one_arg(int argc, char **argv, t_heads head, char **input)
{
	input = ft_split(argv[1], ' ');
	if (!input[0])
	{
		free(input);
		exit(0);
	}
	if (check_stdin(argc, input, 0, 0) == -1)
	{
		free_array(input);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (!input[1])
	{
		free_array(input);
		exit(0);
	}
	head.a = input_to_stack(input, head.a, 0);
	free_array(input);
	return (head);
}

static t_heads	many_arg(int argc, char **argv, t_heads head)
{
	if (check_stdin(argc, argv, 1, 0) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	head.a = input_to_stack(argv, head.a, 1);
	return (head);
}

int	main(int argc, char **argv)
{
	t_heads	head;
	char	**input;
	int		flag;

	flag = 0;
	if (argc <= 1)
		return (0);
	head.a = NULL;
	head.b = NULL;
	input = NULL;
	if (argv[1] == NULL)
		return (0);
	if (argc == 2)
		head = one_arg(argc, argv, head, input);
	else
		head = many_arg(argc, argv, head);
	flag = flag_check(head);
	if (flag == 0 && check_order(head.a) == -1)
		head.a = sort(head);
	head.a = free_stack(head.a);
	return (0);
}
