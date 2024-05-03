/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/24 17:05:40 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	min_to_top(t_stack **stack, char stack_name, int l)
{
	t_stack	*min;
	int		i;

	min = findmin_int(*stack);
	i = min->order;
	if (i <= (l / 2))
	{
		while (i-- > 0)
			rotate(stack, stack_name);
	}
	else
	{
		while (i++ < l)
			rev_rotate(stack, stack_name);
	}
}

void	sort_three(t_stack **stack, char stack_name)
{
	t_stack	*max_node;
	int		max_number;

	max_node = findmax_int(*stack);
	max_number = max_node->num;
	if ((*stack)->num == max_number)
		rotate(stack, stack_name);
	else if ((*stack)->next->num == max_number)
		rev_rotate(stack, stack_name);
	if ((*stack)->next->num < (*stack)->num)
		swap(stack, stack_name);
}

bool	check_sort(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	len_a = ft_lstsize(*stack_a);
	push_it_bro(stack_a, stack_b, len_a, len_a / 2);
	sort_three(stack_a, 'a');
	reset_cost(*stack_b);
	push_it_again(stack_a, stack_b);
	min_to_top(stack_a, 'a', ft_lstsize(*stack_a));
}
