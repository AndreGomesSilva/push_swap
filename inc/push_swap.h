/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:25:10 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/01 16:22:21 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EXIT_OK 0
# define EXIT_FAIL 1
# define TRUE 1
# define FALSE 0
# define ERROR (-1)
# define LIMIT_MAX_INT 2147483647
# define LIMIT_MIN_INT (-2147483648)

# include "../libraries/libft/inc/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int		value;
	struct s_stack	*next;
	struct s_stack	*previous;
	int 	middle_value;
	int 	chunk;
}			t_stack;

int is_valid_args(char **str);
void new_node(t_stack **stack, int value);
t_stack *last_node(t_stack *stack);
int free_node(t_stack *head);
void swap_node(t_stack **stack, char *flag);
void rotate_list(t_stack **stack, char* flag);
void push_to_stack(t_stack **src, t_stack **dest, char *flag);
int	list_len(t_stack **stack);
int	list_len_chunk(t_stack **stack, int chunk);
void reverse_rotate(t_stack	**stack, char *flag);
void short_numbers(t_stack **a);
long int ft_strtol(char *str, char **endptr, int base);
void move_numbers(t_stack **a,t_stack **b);
void set_middle_value(t_stack **stack);
int	check_chunk_great_node(t_stack *stack, int check, int chunk);
void set_middle_chunk(t_stack **stack, int chunk);
int 	check_ascending_order(t_stack **a, int chunk);
int 	check_descending_order(t_stack **b, int chunk);
void init_sort_chunk(t_stack **a, t_stack**b);

#endif
