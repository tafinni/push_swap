/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:53:45 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 13:53:47 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_heads	move_counter(t_heads head, int flag)
{
	if (flag == 1)
	{
		head.sign = 1;
		head.a_rounds = head.a_rot;
		head.b_rounds = head.b_rot;
		if (head.a_rot > head.b_rot)
			head.moves = head.a_rot;
		else
			head.moves = head.b_rot;
	}
	else if (flag == 2)
	{
		head.sign = 2;
		head.a_rounds = head.a_rev;
		head.b_rounds = head.b_rev;
		if (head.a_rev > head.b_rev)
			head.moves = head.a_rev;
		else
			head.moves = head.b_rev;
	}
	return (head);
}

t_heads	move_counter_two(t_heads head, int flag)
{
	if (flag == 3)
	{
		head.a_rounds = head.a_rot;
		head.b_rounds = head.b_rev;
		head.sign = 3;
		head.moves = head.a_rot + head.b_rev;
	}
	else if (flag == 4)
	{
		head.a_rounds = head.a_rev;
		head.b_rounds = head.b_rot;
		head.sign = 4;
		head.moves = head.a_rev + head.b_rot;
	}
	return (head);
}

int	flag_check(t_heads head)
{
	if (check_duplicates(head.a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

char	**new_input(char **argv)
{
	char	**result;

	result = ft_split(argv[1], ' ');
	return (result);
}
