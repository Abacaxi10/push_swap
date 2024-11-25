/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:11:33 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/25 15:49:39 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_duplicate(t_stack_node *a, int n);
int				error_syntax(char *str);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

void			init_stack_a(t_stack_node **a, char **av);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);

void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

void			sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
#endif