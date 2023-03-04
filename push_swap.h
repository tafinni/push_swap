#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h> 

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
	struct s_stack *previous;
}	t_stack;

typedef struct s_heads
{
	t_stack *a;
	t_stack *b;
	int		second;
	int		last;
	int		mid_value;
	int		listlen;
	int		rot;
	int		rev;
}	t_heads;

t_stack *swap(t_stack *start, int sign);
t_stack	*rotate(t_stack *start, int sign);
t_stack	*reverse_rotate(t_stack *start, int sign);
t_heads	push_to_b(t_heads head);
t_heads	push_to_a(t_heads head);


int		check_order(t_stack *start);
int		list_lenght(t_stack *start);
void	free_stack(t_stack *start);
int		find_lowest(t_stack *start); 
int		find_highest(t_stack *start);
int		middle_value(t_stack *start);
t_stack	*last_node(t_stack *start);
t_stack	*pushed_node_too_high_a(t_heads head);
t_heads	move_lowest_to_top_a(t_heads head);

t_stack	*arrange(t_heads head);
t_stack	*arrange_three(t_stack *start);
t_stack	*arrange_four(t_heads head);


int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif