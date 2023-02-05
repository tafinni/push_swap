#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include <stdio.h> //for printf()

typedef struct s_stack
{
	int	value; 
	struct s_stack *next;
	struct s_stack *previous;
	
}	t_stack;

//operations
t_stack *reverse_rotate_a(t_stack *beginning);
t_stack *rotate_a(t_stack *beginning);
t_stack *swap_a(t_stack *beginning);
t_stack	*remove_beginning(t_stack *beginning);
t_stack *push_to_other_stack(t_stack *current, t_stack *destination);
//libft
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);
//helpers
int	find_highest(t_stack *beginning);
int	find_lowest(t_stack *beginning);
t_stack *go_to_last(t_stack *beginning);
int	list_lenght(t_stack *beginning);

#endif