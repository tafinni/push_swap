/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:36:10 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/22 15:36:12 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	long int		value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_heads
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	t_stack	*counter_temp;
	t_stack	*compare_to;
	int		a_value_to_top;
	int		b_value_to_top;
	int		a_best_top;
	int		b_best_top;
	int		moves;
	int		a_second;
	int		b_second;
	int		a_last;
	int		b_last;
	int		a_listlen;
	int		b_listlen;
	int		a_rounds;
	int		b_rounds;
	int		a_rot;
	int		b_rot;
	int		a_rev;
	int		b_rev;
	int		a_highest;
	int		b_highest;
	int		a_second_highest;
	int		a_third_highest;
	int		a_lowest;
	int		b_lowest;
	int		a_least_rounds;
	int		b_least_rounds;
	int		sign;
	int		position;
	int		position_to_top;
	int		count_to_top;
	int		best_move_sign;
}	t_heads;

//DO STACK
t_stack		*input_to_stack(char **argv, t_stack *a_stack, int sign);
t_stack		*free_stack(t_stack *start);

//OPERATIONS
t_stack		*swap(t_stack *start, int sign);
t_stack		*rotate(t_stack *start, int sign);
t_stack		*reverse_rotate(t_stack *start, int sign);
t_heads		push_to_b(t_heads head);
t_heads		push_to_a(t_heads head);
t_heads		rotate_both(t_heads head);
t_heads		reverse_both(t_heads head);

//MOVES
t_heads		count_moves_together(t_heads head);
t_heads		lowest_to_up(t_heads head, int original_len, int rot, int rev);

//SORTERS
t_heads		a_rot_rev_moves(t_heads head, int position);
t_heads		b_rot_rev_moves(t_heads head, t_stack *to_check);

//HELPERS
int			check_order_reverse(t_stack *start);
int			check_order(t_stack *start);
int			list_lenght(t_stack *start);
t_stack		*last_node(t_stack *start);
t_heads		check_if_high_value(t_heads head);
int			check_duplicates(t_stack *list);
long int	ft_atol(const char *str);

//SORT_SMALL
t_stack		*arrange_three_b(t_stack *beginning);
t_stack		*arrange_three(t_stack *start);

//SORT_FEW
t_stack		*arrange_few_a(t_heads head, int lenght);
t_stack		*arrange_few_b(t_heads head, int lenght);

//HELPERS_TWO
int			find_lowest(t_stack *start);
t_heads		reset_values(t_heads head);
t_heads		best_values(t_heads head, t_stack *temp);
t_heads		reset_rounds(t_heads head);
void		free_array(char **str);

//COUNT_MOVES
t_heads		move_counter(t_heads head, int flag);
t_heads		move_counter_two(t_heads head, int flag);
int			flag_check(t_heads head);

//DO_OP
t_heads		do_operations(t_heads head);

//VALUE_FINDERS
t_heads		find_values(t_heads head);

//SORT
t_stack		*sort(t_heads head);

#endif
